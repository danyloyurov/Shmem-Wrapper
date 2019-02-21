#include "shmem_mutex.hpp"
#include "shmem_allocator.hpp"
#include "shmem_defines.hpp"

#include <iostream>

ShmemMutex::ShmemMutex()
    : shmem_memaddr_(nullptr) {
    std::cout << "ShmemMutex()" << std::endl;
}

void ShmemMutex::SetMemAddr(char* shmem_memaddr) {
    std::cout << "ShmemMutex::SetMemAddr()" << std::endl;

    shmem_memaddr_ = shmem_memaddr;
}

bool ShmemMutex::TryLock() {
    std::cout << "ShmemMutex::TryLock()" << std::endl;

    if(nullptr == shmem_memaddr_) {
        return false;
    }

    if(shmem_memaddr_[kMutexByte] == kFree) {
        std::cout << "ShmemMutex::TryLock() - locked" << std::endl;
        shmem_memaddr_[kMutexByte] = kLocked;

        return true;
    }

    return false;
}

void ShmemMutex::Unlock() {
    std::cout << "ShmemMutex::Unlock()" << std::endl;

    shmem_memaddr_[kMutexByte] = kFree;
}
