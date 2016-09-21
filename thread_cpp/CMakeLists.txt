cmake_minimum_required(VERSION 3.5)
project(thread_cpp)
set(TARGET "thread_cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lpthread")

set(SOURCE_FILES main.cpp mThread/mThread.hpp mThread/mThread.hpp mThread/mThreadException.cpp mThread/CommonThread.cpp mThread/ThreadInfo.cpp)
add_executable(${TARGET}  ${SOURCE_FILES})

## Specify libraries to link a library or executable target against
target_link_libraries( ${TARGET}  libpthread.so )