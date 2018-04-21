project(chapterFirstExample)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_DIR}/include $ENV{GTEST_DIR}/include)
link_directories($ENV{GMOCK_HOME}/mybuild/googlemock $ENV{GMOCK_HOME}/mybuild/googlemock/gtest)
add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

set(sources 
   main.cpp 
   SoundexTest.cpp)
add_executable(test ${sources})
target_link_libraries(test gmock)
target_link_libraries(test gtest)

