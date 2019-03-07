#ifndef SHMEM_ALLOCATOR_HPP_
#define SHMEM_ALLOCATOR_HPP_

#include <sys/shm.h>

class ShmemAllocator {
    public:
        static ShmemAllocator& Instance();

        char* GetShmemAddr(const int& size);
        void DeleteShmemAddr(char* shmem_addr, const int& size);

        ShmemAllocator(ShmemAllocator const&) = delete;
        void operator=(ShmemAllocator const&) = delete;
    private:
        ShmemAllocator();
};

#endif // SHMEM_ALLOCATOR_HPP_
