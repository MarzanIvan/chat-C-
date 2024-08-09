cmake_minimum_required(VERSION 3.28)
#boost
project(chat)
FIND_PACKAGE(Boost 1.85.0 REQUIRED COMPONENTS  system thread regex)
set(BOOST_INCLUDE_LIBRARIES thread filesystem system program_options asio date_time)
set(BOOST_ENABLE_CMAKE ON)

set(PQXX /opt/local/lib)
#set(libpqxx_DIR /usr/local/opt/libpq/lib)
find_library(PQXX_LIB pqxx)
#find_library(PQ_LIB pq)
#find_package(libpqxx REQUIRED)

#target_link_libraries(chat -lpqxx -lpq)

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})
#INCLUDE_DIRECTORIES(${BOOST_LIBRARY_INCLUDES})
#include_directories(asio INTERFACE ${boost_asio_SOURCE_DIR}/include)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(/opt/homebrew/Cellar/libpqxx/7.9.2/lib)
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx")
set(CMAKE_CXX_STANDARD 17)

add_executable(chat main.cpp)
target_include_directories(chat PRIVATE ${BOOST_LIBRARY_INCLUDES})

target_link_libraries(chat
        ${USED_LIBS}
        ${PQXX_LIB}
)

