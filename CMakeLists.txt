cmake_minimum_required(VERSION 3.10)

# Set the project name
project(chessrules)

include(CTest)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(FetchContent)

# Download GTest if not present
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
)

# Add GTest to the build
FetchContent_MakeAvailable(googletest)

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

# Set the cppcheck path
set(CMAKE_CXX_CPPCHECK "cppcheck;--enable=all;--language=c++;--suppress=missingIncludeSystem;--suppress=unusedFunction")

# Include directories if necessary
include_directories(include)

# Disable -Werror for Google Test
set_target_properties(gtest PROPERTIES COMPILE_FLAGS "-Wno-error")
# Add the executable
add_executable(chesstest src/main.cpp src/chessboard.cpp src/chessrules.cpp src/chesspiece.cpp src/pawn.cpp src/knight.cpp src/bishop.cpp src/rook.cpp src/queen.cpp src/king.cpp)



# Enable testing
enable_testing()
# Find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(test_chessrules test/test_chessrules.cpp src/chessboard.cpp src/chessrules.cpp src/chesspiece.cpp src/pawn.cpp src/knight.cpp src/bishop.cpp src/rook.cpp src/queen.cpp src/king.cpp)
add_executable(test_pawn test/test_pawn.cpp src/chesspiece.cpp src/pawn.cpp)
add_executable(test_knight test/test_knight.cpp src/chesspiece.cpp src/knight.cpp)
add_executable(test_bishop test/test_bishop.cpp src/chesspiece.cpp src/bishop.cpp)
add_executable(test_rook test/test_rook.cpp src/chesspiece.cpp src/rook.cpp)
add_executable(test_queen test/test_queen.cpp src/chesspiece.cpp src/queen.cpp)
add_executable(test_king test/test_king.cpp src/chesspiece.cpp src/king.cpp)
add_executable(test_chessboard  test/test_chessboard.cpp src/chessboard.cpp src/chesspiece.cpp src/pawn.cpp src/knight.cpp src/bishop.cpp src/rook.cpp src/queen.cpp src/king.cpp)

# Link the test executable with the main project and GoogleTest
#target_link_libraries(test_chessrules gtest gtest_main)0

# Link the test executable with the main project and GoogleTest
target_link_libraries(test_chessrules ${GTEST_LIBRARIES} gmock_main pthread)
target_link_libraries(test_pawn ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_knight ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_bishop ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_rook ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_queen ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_king ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_chessboard ${GTEST_LIBRARIES} pthread)

# Add the test to CTest
add_test(NAME ChessRulesTest COMMAND test_chessrules --gtest_output=json:chessrules_report.json)
add_test(NAME PawnTest COMMAND test_pawn --gtest_output=json:pawn_report.json)
add_test(NAME KnightTest COMMAND test_knight --gtest_output=json:knight_report.json)
add_test(NAME BishopTest COMMAND test_bishop --gtest_output=json:bishop_report.json)
add_test(NAME RookTest COMMAND test_rook --gtest_output=json:rook_report.json)
add_test(NAME QueenTest COMMAND test_queen --gtest_output=json:queen_report.json)
add_test(NAME KingTest COMMAND test_king --gtest_output=json:king_report.json)
add_test(NAME ChessBoardTest COMMAND test_chessboard --gtest_output=json:chessboard_report.json)