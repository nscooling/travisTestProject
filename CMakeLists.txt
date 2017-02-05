cmake_minimum_required(VERSION 2.8.4)
include_directories ("./inc")
project(testProject)
enable_testing()

# Enable ExternalProject CMake module
include(ExternalProject)

# Set the build type if it isn't already
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty)

# Add gtest
ExternalProject_Add(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    TIMEOUT 10
    # Force separate output paths for debug and release builds to allow easy
    # identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
               -Dgtest_force_shared_crt=ON
    # Disable install step
    INSTALL_COMMAND ""
    # Wrap download, configure and build steps in a script to log output
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
include_directories(${source_dir}/googletest/include)


set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wno-ignored-qualifiers -pedantic -O0 -g3 -fmessage-length=0 -MMD -MP -MF -MT -flto -Wl")

file(GLOB SOURCE_FILES ./src/*.cpp)

# Create dependency of MainTest on googletest
# add_dependencies(testProject googletest)


add_executable(testProject ${SOURCE_FILES})

# target_link_libraries(testProject gtest gtest_main pthread)
# Specify MainTest's link libraries
ExternalProject_Get_Property(googletest binary_dir)

set(Suffix ".a")
set(Pthread "-pthread")

target_link_libraries(
    testProject
    ${binary_dir}/googlemock/gtest/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix}
    ${binary_dir}/googlemock/gtest/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${Suffix}
    ${Pthread})

add_test(testProjectTest testProject)
