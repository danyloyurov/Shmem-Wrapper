#include "shmem_server.hpp"

extern "C" {
#include "shmem.h"
}

#include <string.h>

ipm_broker::ShmemServer::ShmemServer(const char* name)
  : descriptor_name_(name),
    closed_encrypting_key_(0),
    shared_memory_address_(get_shmem_address(name)) {
}

ipm_broker::ShmemServer::~ShmemServer() {
  close_descriptor(descriptor_name_.c_str());
}

ipm_broker::error::MessageError ipm_broker::ShmemServer::DispatchMessage(void* data, int& size) {
  if(NULL == shared_memory_address_) return ipm_broker::error::kNullPointer;

  memcpy(data, shared_memory_address_, 100);

  return ipm_broker::error::kSuccess;
}
