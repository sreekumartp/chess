cmake_minimum_required(VERSION 3.10)

# Set the project name
project(chessrules)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(chessrules src/main.cpp src/chessboard.cpp src/chessrules.cpp src/chesspiece.cpp src/pawn.cpp)

# Include directories if necessary
include_directories(include)

# Enable testing
enable_testing()
# Find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(test_chessrules test/test_chessrules.cpp src/chessrules.cpp)
add_executable(test_pawn test/test_pawn.cpp src/chesspiece.cpp src/pawn.cpp)
add_executable(test_knight test/test_knight.cpp src/chesspiece.cpp src/knight.cpp)
add_executable(test_bishop test/test_bishop.cpp src/chesspiece.cpp src/bishop.cpp)
add_executable(test_rook test/test_rook.cpp src/chesspiece.cpp src/rook.cpp)
add_executable(test_queen test/test_queen.cpp src/chesspiece.cpp src/queen.cpp)
add_executable(test_king test/test_king.cpp src/chesspiece.cpp src/king.cpp)

# Link the test executable with the main project and GoogleTest
#target_link_libraries(test_chessrules gtest gtest_main)0

# Link the test executable with the main project and GoogleTest
target_link_libraries(test_chessrules ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_pawn ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_knight ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_bishop ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_rook ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_queen ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_king ${GTEST_LIBRARIES} pthread)

# Add the test to CTest
add_test(NAME ChessRulesTest COMMAND test_chessrules)
add_test(NAME PawnTest COMMAND test_pawn)
add_test(NAME KnightTest COMMAND test_knight)
add_test(NAME BishopTest COMMAND test_bishop)
add_test(NAME RookTest COMMAND test_rook)
add_test(NAME QueenTest COMMAND test_queen)
add_test(NAME KingTest COMMAND test_king)