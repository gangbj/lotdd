project(design)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_DIR}/include $ENV{GTEST_DIR}/include $ENV{JSONCPP_HOME}/include $ENV{CURL_HOME}/include)
link_directories($ENV{GMOCK_HOME}/mybuild/googlemock $ENV{GMOCK_HOME}/mybuild/googlemock/gtest $ENV{JSONCPP_HOME}/build/libs $ENV{CURL_HOME}/build/lib)
add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

set(sources 
   main.cpp 
   CurlHttpTest.cpp CurlHttp.cpp
   AddressExtractorTest.cpp AddressExtractor.cpp
   PlaceDescriptionServiceTest.cpp PlaceDescriptionService.cpp)
add_executable(pdstest ${sources})
target_link_libraries(pdstest gmock)
target_link_libraries(pdstest gtest)
target_link_libraries(pdstest jsoncpp)
target_link_libraries(pdstest curl)

