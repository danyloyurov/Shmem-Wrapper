#include "shmem_data.hpp"
#include <cstring>

ShmemData::ShmemData(const char* data, const short& data_size)
    : data_(nullptr),
      data_size_(0) {
    SetData(data, data_size);
}

ShmemData::ShmemData(const ShmemData& shmem_data) {
    SetData(shmem_data.data_, shmem_data.data_size_);
}

ShmemData::~ShmemData() {
    delete data_;
}

void ShmemData::SetData(const char* data, const short& data_size) {
    delete data_;

    data_ = new char[data_size];
    memcpy(data_, data, data_size);
    data_size_ = data_size;
}
