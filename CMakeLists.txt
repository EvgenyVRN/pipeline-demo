# Use vcpkg
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()


cmake_minimum_required(VERSION 3.10)

project(pipeline LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR})

# project options
option(ENABLE_TESTS "Enable tests" OFF)

# compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
        add_compile_options(
              -Werror
              -pedantic-errors

              -Wall
              -Wextra
              -Wpedantic

              -Wcast-align
              -Wcast-qual
              -Wconversion
              -Wctor-dtor-privacy
              -Wduplicated-branches
              -Wduplicated-cond
              -Wfloat-equal
              -Wlogical-op
              -Wnon-virtual-dtor
              -Wold-style-cast
              -Woverloaded-virtual
              -Wredundant-decls
              -Wsign-conversion
              -Wsign-promo
        )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        add_compile_options(/W4 /WX)
else()
        message("unknown compiler")
endif()

#packages
find_package(glog CONFIG REQUIRED)

find_package(Boost REQUIRED COMPONENTS filesystem)
include_directories(${BOOST_INCLUDE_DIR})

#library
add_subdirectory(src)

#main
add_executable(pipeline main.cpp)
target_link_libraries(pipeline PRIVATE pipeline-lib)
target_link_libraries(pipeline PRIVATE ${Boost_LIBRARIES}) # Boost::filesystem
target_link_libraries(pipeline PRIVATE glog::glog)

#tests
if (${ENABLE_TESTS})
    add_subdirectory(tests)
endif()
