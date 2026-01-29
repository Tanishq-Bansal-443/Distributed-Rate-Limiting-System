cmake_minimum_required(VERSION 3.16)
project(distributed_rate_limiter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(rate_limiter
    src/main.cpp
)
