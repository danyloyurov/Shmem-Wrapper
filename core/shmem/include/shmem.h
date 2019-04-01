#ifndef CORE_SHMEM_INCLUDE_SHMEM_H_
#define CORE_SHMEM_INCLUDE_SHMEM_H_

void* create_shmem_address(const char* name, int size);
void* get_shmem_address(const char* name);
void close_descriptor(const char* name);

#endif // CORE_SHMEM_INCLUDE_SHMEM_H_
