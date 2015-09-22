cmake_minimum_required(VERSION 3.0)
project(WykopMainDataAlanyzer)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCE_FILES "src/*.cpp" "src/Characteristics/*.cpp")
add_executable(WykopMainDataAlanyzer ${SOURCE_FILES})

TARGET_LINK_LIBRARIES( WykopMainDataAlanyzer ${Boost_LIBRARIES} )