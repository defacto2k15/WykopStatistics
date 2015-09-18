cmake_minimum_required(VERSION 3.0)
project(WykopTopicsFetcher)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ".")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp pugixml.cpp ValuesFromNodeExtractor.cpp DiggData.cpp DiggDataToXmlWriter.cpp DiggDataToXmlWriter.h)
add_executable(WykopTopicsFetcher ${SOURCE_FILES})