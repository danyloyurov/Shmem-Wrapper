#ifndef SHMEM_CLIENT_HPP_
#define SHMEM_CLIENT_HPP_

#include "shmem_data.hpp"
#include "shmem_mutex.hpp"
#include <queue>
#include <sys/shm.h>

class ShmemClient {
    public:
        ShmemClient(const int& shmem_size);
        ~ShmemClient();

        void RegisterClient();
        void DispatchQueue();
        void WriteData(const ShmemData& data);
    private:
        char* shmem_memaddr_;
        int shmem_size_;
        int shmem_id_;

        ShmemMutex write_mutex_;
        std::queue<ShmemData> write_queue_;
};

#endif // SHMEM_CLIENT_HPP_
