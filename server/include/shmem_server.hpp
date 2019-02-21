#ifndef SHMEM_SERVER_HPP_
#define SHMEM_SERVER_HPP_

#include "shmem_data.hpp"

#include <queue>
#include "shmem_mutex.hpp"

class ShmemServer {
    public:
        ShmemServer(const int& shmem_size);
        ~ShmemServer();

        void RegisterServer();
        std::queue<ShmemData> DispatchQueue();
        void PeekData();
    private:
        char* shmem_memaddr_;
        int shmem_size_;
        int shmem_id_;

        ShmemMutex read_mutex_;
        std::queue<ShmemData> read_queue_;
};

#endif // SHMEM_SERVER_HPP_
