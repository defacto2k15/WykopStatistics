cmake_minimum_required(VERSION 3.0)
project(WykopMainDataAlanyzer)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_definitions(-std=c++11)
# Extra warnings
add_definitions(-Wextra -Wall)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/")

file(GLOB SRC_FILES "src/*.cpp" "src/Characteristics/*.cpp")
add_executable(WykopMainDataAlanyzer ${SRC_FILES})
TARGET_LINK_LIBRARIES( WykopMainDataAlanyzer ${Boost_LIBRARIES} )

# we may or may not want to build tests
option(BuildTests "BuildTests" OFF)

if(BuildTests)
    set(GMOCK_ROOT lib/gmock-1.7.0)
    # Google Mock & Test
    ###############################################################################
    add_subdirectory(${GMOCK_ROOT})
    include_directories(${GMOCK_ROOT}/include)
    include_directories(${GMOCK_ROOT}/gtest/include)

    set(TEST_EXECUTABLE_NAME "tests")
    # Test files
    file(GLOB TEST_FILES "test/*.cpp")

    # Don't include Main.cpp from src
    file(GLOB MAIN_SRC "src/main.cpp")
    list(REMOVE_ITEM SRC_FILES ${MAIN_SRC})

    add_executable("${TEST_EXECUTABLE_NAME}" ${TEST_FILES} ${SRC_FILES})
    # Set link libraries (order matters)
    target_link_libraries("${TEST_EXECUTABLE_NAME}" gmock gtest pthread)

    # Include root directory
    include_directories(BEFORE ".")
    include_directories(BEFORE "src/")
endif()