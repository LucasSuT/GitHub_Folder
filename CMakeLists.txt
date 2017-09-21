cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp utSort.h include/Shapes.h include/Media.h include/Sort.h Media.cpp Shapes.cpp )

# Link runTests with what we want to test and the GTest and pthread library
add_executable(hw1 main.cpp utSort.h include/Shapes.h include/Media.h include/Sort.h Media.cpp Shapes.cpp)
target_link_libraries(hw1 ${GTEST_LIBRARIES} pthread)
