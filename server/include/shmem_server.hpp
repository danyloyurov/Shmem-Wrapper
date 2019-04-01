#ifndef SERVER_INCLUDE_SHMEM_SERVER_HPP_
#define SERVER_INCLUDE_SHMEM_SERVER_HPP_

#include "error.hpp"

#include <string>

namespace ipm_broker {

class ShmemServer {
  public:
    explicit ShmemServer(const char* name);
    ~ShmemServer();
    ShmemServer(const ShmemServer&) = delete;
    void operator=(const ShmemServer&) = delete;

    error::MessageError Login();
    error::MessageError DispatchMessage(void* data, int& size);
  private:
    std::string descriptor_name_;
    int closed_encrypting_key_;
    void* shared_memory_address_;
};

} // ipm_broker

#endif // SERVER_INCLUDE_SHMEM_SERVER_HPP_
