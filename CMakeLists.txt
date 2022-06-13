cmake_minimum_required(VERSION 3.16)
project(slave_rpc)

# include (cmake/util.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined")
set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(.)
include_directories(/usr/include)
include_directories(/usr/include/mysql)
link_directories(/usr/lib)
link_directories(/usr/lib/mysql)

set(LIB_SRC
        gen-cpp/Master.cpp
        gen-cpp/master_types.cpp
        gen-cpp/master_constants.cpp
        gen-cpp/Slave.cpp
        gen-cpp/slave_types.cpp
        gen-cpp/slave_constants.cpp
        db/mysql_client.cpp
        db/mysql_rsync.cpp
        conf/conf.cpp
        conf/dbconf.cpp
        thread/mutex.cpp
        thread/thread.cpp
        thread/threadpool.cpp
        thread/threadgroup.cpp
        log/elog_utils.cpp
        log/elog_port.cpp
        log/elog_file_port.cpp
        log/elog_file.cpp
        log/elog_buf.cpp
        log/elog_async.cpp
        log/elog.cpp
        )

add_library(rpc SHARED ${LIB_SRC})

set(LIB_LIB
        rpc
        pthread
        thrift
        thriftnb
        event
        mysqlclient
        )

add_executable(slave_server gen-cpp/Slave_server.cpp)
add_dependencies(slave_server rpc)
target_link_libraries(slave_server rpc ${LIB_LIB})

add_executable(threadgroup_test thread/threadgroup_test.cpp)
add_dependencies(threadgroup_test rpc)
target_link_libraries(threadgroup_test rpc ${LIB_LIB})

add_executable(master_client client/master_client.cpp)
add_dependencies(master_client rpc)
target_link_libraries(master_client rpc ${LIB_LIB})

add_executable(thread_test thread/thread_test.cpp)
add_dependencies(thread_test rpc)
target_link_libraries(thread_test rpc ${LIB_LIB})