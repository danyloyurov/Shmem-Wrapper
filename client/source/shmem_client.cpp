#include "shmem_client.hpp"
#include "shmem_allocator.hpp"

#include <cstring>
#include <iostream>
#include <sys/mman.h>

ShmemClient::ShmemClient(const int& shmem_size)
    : shmem_memaddr_(ShmemAllocator::Instance().GetShmemAddr(shmem_size)),
      shmem_size_(shmem_size) {
}

ShmemClient::~ShmemClient() {
    std::cout << "~ShmemClient()" << std::endl;

    ShmemAllocator::Instance().DeleteShmemAddr(shmem_memaddr_--, shmem_size_);
}

void ShmemClient::LoginClient() {
    std::cout << "ShmemClient::LoginClient()" << std::endl;

    write_mutex_.SetMemAddr(shmem_memaddr_);
    shmem_memaddr_++; //One byte reserve for mutex
}

void ShmemClient::WriteData(const ShmemData& data) {

}
