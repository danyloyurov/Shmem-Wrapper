#ifndef SHMEM_MUTEX_HPP_
#define SHMEM_MUTEX_HPP_

class ShmemMutex {
    public:
        ShmemMutex();

        void SetMemAddr(char* shmem_memaddr);

        bool TryLock();
        void Unlock();
    private:
        char* shmem_memaddr_;

        const char kFree = 0;
        const char kLocked = 1;
};

#endif // SHMEM_MUTEX_HPP_
