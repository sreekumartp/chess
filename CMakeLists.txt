cmake_minimum_required(VERSION 3.10)

# Set the project name
project(chessrules)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
#add_executable(chessrules main.cpp chessrules.cpp)

# Include directories if necessary
include_directories(include)

# Enable testing
enable_testing()
# Find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(test_chessrules test/test_chessrules.cpp chessrules.cpp)

# Link the test executable with the main project and GoogleTest
#target_link_libraries(test_chessrules gtest gtest_main)0

# Link the test executable with the main project and GoogleTest
target_link_libraries(test_chessrules ${GTEST_LIBRARIES} pthread)

# Add the test to CTest
add_test(NAME ChessRulesTest COMMAND test_chessrules)