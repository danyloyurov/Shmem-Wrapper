#include "shmem_allocator.hpp"

#include <sys/mman.h>

ShmemAllocator::ShmemAllocator() {

}

ShmemAllocator& ShmemAllocator::Instance() {
    static ShmemAllocator object;

    return object;
}

void* ShmemAllocator::GetShmemAddr(const int& size) {
    return mmap(0, size, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, 0, 0);
}

void ShmemAllocator::DeleteShmemAddr(char* shmem_addr, const int& size) {
    munmap(shmem_addr, size);
}
