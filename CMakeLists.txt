cmake_minimum_required(VERSION 2.8)
project(HttpRouter)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -Wextra")

set(SOURCE_FILES
        include/HttpHandlers.h
        include/HttpRouter.h
        src/HttpHandlers.cpp
        src/HttpRouter.cpp
        src/HttpRouterTest.cpp)

add_executable(HttpRouter ${SOURCE_FILES})
target_link_libraries(HttpRouter PocoFoundation
    PocoNetSSL
    PocoUtil
    PocoCrypto
    PocoNet
    PocoXML)