cmake_minimum_required(VERSION 2.8.4)
include_directories ("./inc")
project(testProject)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wno-ignored-qualifiers -pedantic -O0 -g3 -fmessage-length=0 -MMD -MP -MF -MT -flto -Wl,--allow-multiple-definition")

file(GLOB SOURCE_FILES ./src/*.cpp)



add_executable(testProject ${SOURCE_FILES})
target_link_libraries(testProject gtest gtest_main pthread)
