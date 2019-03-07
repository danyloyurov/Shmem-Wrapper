cmake_minimum_required(VERSION 2.8)
project(shmem_client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(INCLUDE
../common/api
../common/include
include)

set(SOURCE
../common/source/shmem_allocator.cpp
../common/source/shmem_data.cpp
../common/source/shmem_mutex.cpp
source/shmem_client.cpp
)

include_directories(${INCLUDE})

add_executable(${PROJECT_NAME} ${SOURCE})
