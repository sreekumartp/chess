#include <gtest/gtest.h>
#include <gtest/gtest.h>
#include "../include/chessrules.hpp"

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

// Test for compute_coordinates_up function
TEST(ChessRulesTest, ComputeCoordinatesUp) {
    // Test case 1: Point in the middle of the board
    {
        int x = 4, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {4, 5}, {4, 6}, {4, 7}, {4, 8}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 2: Point at the top edge of the board
    {
        int x = 4, y = 8, max_n = 4;
        auto coordinates = compute_coordinates_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {};
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
    }

    // Test case 3: Point near the top edge of the board
    {
        int x = 4, y = 6, max_n = 4;
        auto coordinates = compute_coordinates_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {4, 7}, {4, 8}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 4: Point at the bottom edge of the board
    {
        int x = 4, y = 1, max_n = 4;
        auto coordinates = compute_coordinates_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {4, 2}, {4, 3}, {4, 4}, {4, 5}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }
}
// Test for compute_coordinates_down function
TEST(ChessRulesTest, ComputeCoordinatesDown) {
    // Test case 1: Point in the middle of the board
    {
        int x = 4, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {4, 3}, {4, 2}, {4, 1}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 2: Point at the bottom edge of the board
    {
        int x = 4, y = 1, max_n = 4;
        auto coordinates = compute_coordinates_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {};
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
    }

    // Test case 3: Point near the bottom edge of the board
    {
        int x = 4, y = 3, max_n = 4;
        auto coordinates = compute_coordinates_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {4, 2}, {4, 1}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 4: Point at the top edge of the board
    {
        int x = 4, y = 8, max_n = 4;
        auto coordinates = compute_coordinates_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {4, 7}, {4, 6}, {4, 5}, {4, 4}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }
}

// Test for compute_coordinates_left function
TEST(ChessRulesTest, ComputeCoordinatesLeft) {
    // Test case 1: Point in the middle of the board
    {
        int x = 4, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_left(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {3, 4}, {2, 4}, {1, 4}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 2: Point at the left edge of the board
    {
        int x = 1, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_left(x, y, max_n);
        std::vector<Point> expected_coordinates = {};
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
    }

    // Test case 3: Point near the left edge of the board
    {
        int x = 3, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_left(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {2, 4}, {1, 4}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 4: Point at the right edge of the board
    {
        int x = 8, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_left(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {7, 4}, {6, 4}, {5, 4}, {4, 4}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }
}

// Test for compute_coordinates_right function
TEST(ChessRulesTest, ComputeCoordinatesRight) {
    // Test case 1: Point in the middle of the board
    {
        int x = 4, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_right(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {5, 4}, {6, 4}, {7, 4}, {8, 4}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 2: Point at the right edge of the board
    {
        int x = 8, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_right(x, y, max_n);
        std::vector<Point> expected_coordinates = {};
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
    }

    // Test case 3: Point near the right edge of the board
    {
        int x = 6, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_right(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {7, 4}, {8, 4}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 4: Point at the left edge of the board
    {
        int x = 1, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_right(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {2, 4}, {3, 4}, {4, 4}, {5, 4}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }
}

// Test for compute_coordinates_right_up function
TEST(ChessRulesTest, ComputeCoordinatesRightUp) {
    // Test case 1: Point in the middle of the board
    {
        int x = 4, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_right_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {5, 5}, {6, 6}, {7, 7}, {8, 8}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 2: Point at the top-right edge of the board
    {
        int x = 8, y = 8, max_n = 4;
        auto coordinates = compute_coordinates_right_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {};
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
    }

    // Test case 3: Point near the top-right edge of the board
    {
        int x = 6, y = 6, max_n = 4;
        auto coordinates = compute_coordinates_right_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {7, 7}, {8, 8}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 4: Point at the bottom-left edge of the board
    {
        int x = 1, y = 1, max_n = 4;
        auto coordinates = compute_coordinates_right_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {2, 2}, {3, 3}, {4, 4}, {5, 5}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }
}

// Test for compute_coordinates_left_up function
TEST(ChessRulesTest, ComputeCoordinatesLeftUp) {
    // Test case 1: Point in the middle of the board
    {
        int x = 4, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_left_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {3, 5}, {2, 6}, {1, 7}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 2: Point at the top-left edge of the board
    {
        int x = 1, y = 8, max_n = 4;
        auto coordinates = compute_coordinates_left_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {};
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
    }

    // Test case 3: Point near the top-left edge of the board
    {
        int x = 2, y = 7, max_n = 4;
        auto coordinates = compute_coordinates_left_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {1, 8}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 4: Point at the bottom-right edge of the board
    {
        int x = 8, y = 1, max_n = 4;
        auto coordinates = compute_coordinates_left_up(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {7, 2}, {6, 3}, {5, 4}, {4, 5}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }
}

// Test for compute_coordinates_left_down function
TEST(ChessRulesTest, ComputeCoordinatesLeftDown) {
    // Test case 1: Point in the middle of the board
    {
        int x = 4, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_left_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {3, 3}, {2, 2}, {1, 1}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 2: Point at the bottom-left edge of the board
    {
        int x = 1, y = 1, max_n = 4;
        auto coordinates = compute_coordinates_left_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {};
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
    }

    // Test case 3: Point near the bottom-left edge of the board
    {
        int x = 2, y = 2, max_n = 4;
        auto coordinates = compute_coordinates_left_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {1, 1}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 4: Point at the top-right edge of the board
    {
        int x = 8, y = 8, max_n = 4;
        auto coordinates = compute_coordinates_left_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {7, 7}, {6, 6}, {5, 5}, {4, 4}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }
}
// Test for compute_coordinates_right_down function
TEST(ChessRulesTest, ComputeCoordinatesRightDown) {
    // Test case 1: Point in the middle of the board
    {
        int x = 4, y = 4, max_n = 4;
        auto coordinates = compute_coordinates_right_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {5, 3}, {6, 2}, {7, 1}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 2: Point at the bottom-right edge of the board
    {
        int x = 8, y = 1, max_n = 4;
        auto coordinates = compute_coordinates_right_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {};
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
    }

    // Test case 3: Point near the bottom-right edge of the board
    {
        int x = 7, y = 2, max_n = 4;
        auto coordinates = compute_coordinates_right_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {8, 1}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }

    // Test case 4: Point at the top-left edge of the board
    {
        int x = 1, y = 8, max_n = 4;
        auto coordinates = compute_coordinates_right_down(x, y, max_n);
        std::vector<Point> expected_coordinates = {
            {2, 7}, {3, 6}, {4, 5}, {5, 4}
        };
        EXPECT_EQ(coordinates.size(), expected_coordinates.size());
        for (const auto& coord : expected_coordinates) {
            EXPECT_NE(std::find(coordinates.begin(), coordinates.end(), coord), coordinates.end());
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


