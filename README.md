<h4>CmakeFile.txt for asio to include</h4>
<hr>

```cmake
cmake_minimum_required(VERSION 3.28)
#boost
project(chat)
FIND_PACKAGE(Boost 1.85.0 REQUIRED COMPONENTS  system thread regex)
set(BOOST_INCLUDE_LIBRARIES thread filesystem system program_options asio date_time)
set(BOOST_ENABLE_CMAKE ON)

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

set(CMAKE_CXX_STANDARD 14)

add_executable(chat main.cpp)
target_include_directories(chat PRIVATE ${BOOST_LIBRARY_INCLUDES})
target_link_libraries(chat
        ${USED_LIBS}
)
```
<hr>
<h4>Including PQXX library</h4>

```cmake
#PQXX Postgresql library
set(PQXX /opt/local/lib/libpqxx.a)
find_library(PQXX_LIB pqxx)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx")

#Libraries
target_include_directories(chat PRIVATE ${BOOST_LIBRARY_INCLUDES} )
target_link_libraries(chat
        ${USED_LIBS}
        ${PQXX_LIB}
)
```

<hr>