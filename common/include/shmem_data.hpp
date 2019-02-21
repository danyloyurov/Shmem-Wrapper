#ifndef SHMEM_DATA_HPP_
#define SHMEM_DATA_HPP_

struct ShmemData {
    public:
        ShmemData(const char* data, const short& data_size);
        ShmemData(const ShmemData& shmem_data);
        ~ShmemData();

        void SetData(const char* data, const short& data_size);

        char* data_;
        short data_size_;
};


#endif // SHMEM_DATA_HPP_
