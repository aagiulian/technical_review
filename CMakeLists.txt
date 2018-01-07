cmake_minimum_required(VERSION 3.1)

project(technical_review)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set	(SRCS_CLIENT
	 client.cpp
	 GpsSequence.cpp
	)
set	(SRCS_SERVER
	 server.cpp
	)
set	(HEADERS_CLIENT
	client.hpp	
	)

add_executable(server ${SRCS_SERVER})
add_executable(client ${SRCS_CLIENT} ${HEADERS_CLIENT})

#find cppzmq wrapper, installed by make of cppzmq
find_package(cppzmq)
if(cppzmq_FOUND)
	include_directories(${cppzmq_INCLUDE_DIR})
	target_link_libraries(server ${cppzmq_LIBRARY})
	target_link_libraries(client ${cppzmq_LIBRARY})
endif()
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(client Threads::Threads)

