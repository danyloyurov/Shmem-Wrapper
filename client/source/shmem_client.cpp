#include "shmem_client.hpp"
#include "shmem_allocator.hpp"

#include <cstring>
#include <iostream>
#include <sys/mman.h>

ShmemClient::ShmemClient(const int& shmem_size)
    : shmem_size_(shmem_size) {
    std::cout << "ShmemClient()" << std::endl;

    shmem_memaddr_ = reinterpret_cast<char*>(ShmemAllocator::Instance().GetShmemAddr(shmem_size_));

    if((void*)shmem_memaddr_ == MAP_FAILED || shmem_memaddr_ == NULL) {
        std::cout << "\nMAP FAILED\n";
    }
}

ShmemClient::~ShmemClient() {
    std::cout << "~ShmemClient()" << std::endl;

    ShmemAllocator::Instance().DeleteShmemAddr(shmem_memaddr_--, shmem_size_);
}

void ShmemClient::RegisterClient() {
    std::cout << "ShmemClient::RegisterClient()" << std::endl;

    write_mutex_.SetMemAddr(shmem_memaddr_);
    shmem_memaddr_++; //One byte reserve for mutex
}

void ShmemClient::DispatchQueue() {
    std::cout << "ShmemClient::DispatchQueue()" << std::endl;

    if(true == write_queue_.empty()) return;

    // TODO: Implement queue dispatching in case of shmem overflow
}

void ShmemClient::WriteData(const ShmemData& data) {
    std::cout << "ShmemClient::WriteData()" << std::endl;

    if(true == write_mutex_.TryLock()) {
        int offset = 0;

        for(int index = 0; index < shmem_size_; index++) {

            if(shmem_memaddr_[index] == 0) {
                offset = index;
                break;
            }

        }

        std::cout << "Shmem: " << shmem_memaddr_ << std::endl;

        size_t size_segment = sizeof(data.data_size_);

        memcpy(shmem_memaddr_ + offset, &data.data_size_, size_segment);
        offset += size_segment;
        memcpy(shmem_memaddr_ + offset, data.data_, data.data_size_);

        write_mutex_.Unlock();
    } else {
        write_queue_.push(data);
    }

}
