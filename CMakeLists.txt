#write CMakeLists below for compiling 
#GithubBowling.cpp, calculateScore_Github_test.cpp and its dependencies 


## 
## CMakeLists.txt
##
cmake_minimum_required(VERSION 3.5)

project(GithubBowling)

set(CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(main GithubBowling.cpp)
target_link_libraries(main ${GTEST_LIBRARIES} pthread)

add_executable(test calculateScore_Github_test.cpp)
target_link_libraries(test ${GTEST_LIBRARIES} pthread)