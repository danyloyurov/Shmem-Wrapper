#ifndef CLIENT_INCLUDE_SHMEM_CLIENT_HPP_
#define CLIENT_INCLUDE_SHMEM_CLIENT_HPP_

#include "error.hpp"

#include <string>

namespace ipm_broker {

class ShmemClient {
  public:
    explicit ShmemClient(const char* name, const int& size);
    ~ShmemClient();
    ShmemClient(const ShmemClient&) = delete;
    void operator=(const ShmemClient&) = delete;

    error::MessageError Login();
    error::MessageError WriteMessage(const void* data, const int size);
  private:
    std::string descriptor_name_;
    int open_encrypting_key_;
    void* shared_memory_address_;
};

} // ipm_broker

#endif // CLIENT_INCLUDE_SHMEM_CLIENT_HPP_
