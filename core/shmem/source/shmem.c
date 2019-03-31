#include "shmem.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define NULL (0)
#define SHM_ERROR (-1)

void* create_shmem_address(const char* name, int size) {
  void* shmem_address = NULL;
  int file_descriptor = 0;
  int error_code = 0;

  file_descriptor = shm_open(name, O_RDWR, O_CREAT);

  if(SHM_ERROR == file_descriptor) return shmem_address;

  error_code = ftructate(file_descriptor, size);

  if(SHM_ERROR == error_code) return shmem_address;

  shmem_address = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, file_descriptor, NULL);
  close(file_descriptor);
  return shmem_address;
}

void* get_shmem_address(const char* name) {
  struct stat shmem_stat;
  void* shmem_address = NULL;
  int file_descriptor = 0;
  int error_code = 0;

  file_descriptor = shm_open(name, O_RDWR, NULL);

  if(SHM_ERROR == file_descriptor) return shmem_address;

  error_code = fstat(file_descriptor, &shmem_stat);

  if(SHM_ERROR == error_code) return shmem_address;

  shmem_address = mmap(NULL, shmem_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file_descriptor, NULL);
  close(file_descriptor);
  return shmem_address;
}
