#include <gtest/gtest.h>
#include "../include/chessrules.h"

// Test for compute_knights_moves function
TEST(ChessRulesTest, ComputeKnightsMoves) {
    // Test case 1: Knight in the center of the board
    {
        int x = 4, y = 4;
        auto moves = compute_knights_moves(x, y, 8);
        std::vector<Point> expected_moves = {
            {5, 6}, {6, 5}, {6, 3}, {5, 2},
            {3, 2}, {2, 3}, {2, 5}, {3, 6}
        };
        EXPECT_EQ(moves.size(), expected_moves.size());
        for (const auto& move : expected_moves) {
            EXPECT_NE(std::find(moves.begin(), moves.end(), move), moves.end());
        }
    }

    // Test case 2: Knight at the corner of the board
    {
        int x = 1, y = 1;
        auto moves = compute_knights_moves(x, y, 8);
        std::vector<Point> expected_moves = {
            {2, 3}, {3, 2}
        };
        EXPECT_EQ(moves.size(), expected_moves.size());
        for (const auto& move : expected_moves) {
            EXPECT_NE(std::find(moves.begin(), moves.end(), move), moves.end());
        }
    }

    // Test case 3: Knight at the edge of the board
    {
        int x = 8, y = 8;
        auto moves = compute_knights_moves(x, y, 8);
        std::vector<Point> expected_moves = {
            {7, 6}, {6, 7}
        };
        EXPECT_EQ(moves.size(), expected_moves.size());
        for (const auto& move : expected_moves) {
            EXPECT_NE(std::find(moves.begin(), moves.end(), move), moves.end());
        }
    }

    // Test case 4: Knight near the edge of the board
    {
        int x = 2, y = 7;
        auto moves = compute_knights_moves(x, y, 8);
        std::vector<Point> expected_moves = {
            {3, 5}, {4, 6}, {4, 8}, {1, 5}
        };
        EXPECT_EQ(moves.size(), expected_moves.size());
        for (const auto& move : expected_moves) {
            EXPECT_NE(std::find(moves.begin(), moves.end(), move), moves.end());
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}