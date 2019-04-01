#include "shmem_client.hpp"

extern "C" {
#include "shmem.h"
}

#include <string.h>

ipm_broker::ShmemClient::ShmemClient(const char* name, const int& size)
  : descriptor_name_(name),
    open_encrypting_key_(0),
    shared_memory_address_(create_shmem_address(name, size)) {
}

ipm_broker::ShmemClient::~ShmemClient() {
  /*will be in use after sync logic implementation*/
  //close_descriptor(descriptor_name_.c_str());
}

ipm_broker::error::MessageError ipm_broker::ShmemClient::WriteMessage(const void* data, const int size) {
  if(NULL == shared_memory_address_) return ipm_broker::error::kNullPointer;

  memcpy(shared_memory_address_, data, 100);

  return ipm_broker::error::kSuccess;
}

