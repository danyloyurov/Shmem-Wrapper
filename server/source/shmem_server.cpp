#include "shmem_server.hpp"
#include "shmem_allocator.hpp"
#include "shmem_defines.hpp"

#include <iostream>
#include <cstring>
#include <sys/mman.h>

ShmemServer::ShmemServer(const int& shmem_size)
    : shmem_size_(shmem_size) {
    std::cout << "ShmemServer()" << std::endl;

    shmem_memaddr_ = reinterpret_cast<char*>(ShmemAllocator::Instance().GetShmemAddr(shmem_size_));

    if((void*)shmem_memaddr_ == MAP_FAILED || shmem_memaddr_ == NULL) {
        std::cout << "\nMAP FAILED\n";
    }
}

ShmemServer::~ShmemServer() {
    std::cout << "~ShmemServer()" << std::endl;

    ShmemAllocator::Instance().DeleteShmemAddr(shmem_memaddr_--, shmem_size_);
}

void ShmemServer::RegisterServer() {
    std::cout << "ShmemServer::RegisterServer()" << std::endl;

    read_mutex_.SetMemAddr(shmem_memaddr_);
    shmem_memaddr_++; //One byte reserve for mutex
}

std::queue<ShmemData> ShmemServer::DispatchQueue() {
    std::cout << "ShmemServer::DispatchQueue()" << std::endl;

    return read_queue_;
}

void ShmemServer::PeekData() {
    std::cout << "ShmemServer::PeekData()" << std::endl;

    if(true == read_mutex_.TryLock()) {

        size_t data_size = 0;
        int offset = 0;

        while(true) {

            memcpy(&data_size, shmem_memaddr_ + offset, sizeof(ShmemData::data_size_));

            if(data_size == 0) {
                break;
            }

            char* buffer = new char[data_size];
            memcpy(buffer, shmem_memaddr_ + data_size - 1 + offset, data_size);

            ShmemData read_data(buffer, data_size);
            read_queue_.push(read_data);

            offset += sizeof(ShmemData::data_size_);
            offset += data_size;

            delete[] buffer;
        };

        memset(shmem_memaddr_, 0, kShmemSize - kMutexSize);

        read_mutex_.Unlock();
    }
}
