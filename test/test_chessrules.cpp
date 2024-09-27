#include <gtest/gtest.h>
#include "chessrules.hpp"
#include "chessboard.hpp"
// #include "chesspiece.hpp"
// #include "pawn.hpp"
// #include "rook.hpp"
// #include "knight.hpp"
// #include "bishop.hpp"
// #include "queen.hpp"
// #include "king.hpp"

class ChessRulesTest : public ::testing::Test {
public:
    ChessRules rules;
    Board board;

    void SetUp() override {
       
        // Initialize the board with pieces for testing
       
       board.InitialiseBoard();
       
    }

    void TearDown() override 
    {
        board.clearBoard();
    }
};

TEST_F(ChessRulesTest, DISABLED_GenerateMovesForPawn) {
    Point position = {0, 1};
 
    board.printBoard();

    auto moves = rules.GenerateMoves(position, board);

    ASSERT_EQ(moves.size(), 1);
    ASSERT_EQ(moves[0].size(), 2);
    EXPECT_EQ(moves[0][0], Point(0, 2));
    EXPECT_EQ(moves[0][1], Point(0, 3));
}

TEST_F(ChessRulesTest, GenerateMovesForRook) {
    Point position = {0, 0};
    board.printBoard();
    auto moves = rules.GenerateMoves(position, board);
    ASSERT_EQ(moves.size(), 4);
    EXPECT_EQ(moves[0].size(), 7); // Up
    EXPECT_EQ(moves[1].size(), 7); // Right
    EXPECT_EQ(moves[2].size(), 0); // Down
    EXPECT_EQ(moves[3].size(), 0); // Left
}

TEST_F(ChessRulesTest, DISABLED_GenerateMovesForKnight) {
    Point position = {1, 0};
    auto moves = rules.GenerateMoves(position, board);
    ASSERT_EQ(moves.size(), 8);
    EXPECT_EQ(moves[0][0], Point(2, 2));
    EXPECT_EQ(moves[1][0], Point(3, 1));
    EXPECT_EQ(moves[2][0], Point(3, -1));
    EXPECT_EQ(moves[3][0], Point(2, -2));
    EXPECT_EQ(moves[4][0], Point(0, -2));
    EXPECT_EQ(moves[5][0], Point(-1, -1));
    EXPECT_EQ(moves[6][0], Point(-1, 1));
    EXPECT_EQ(moves[7][0], Point(0, 2));
}

TEST_F(ChessRulesTest, DISABLED_GenerateMovesForBishop) {
    Point position = {2, 0};
    auto moves = rules.GenerateMoves(position, board);
    ASSERT_EQ(moves.size(), 4);
    EXPECT_EQ(moves[0].size(), 6); // Right Up
    EXPECT_EQ(moves[1].size(), 0); // Right Down
    EXPECT_EQ(moves[2].size(), 0); // Left Down
    EXPECT_EQ(moves[3].size(), 0); // Left Up
}

TEST_F(ChessRulesTest, DISABLED_GenerateMovesForQueen) {
    Point position = {3, 0};
    auto moves = rules.GenerateMoves(position, board);
    ASSERT_EQ(moves.size(), 8);
    EXPECT_EQ(moves[0].size(), 7); // Up
    EXPECT_EQ(moves[1].size(), 6); // Right Up
    EXPECT_EQ(moves[2].size(), 0); // Right
    EXPECT_EQ(moves[3].size(), 0); // Right Down
    EXPECT_EQ(moves[4].size(), 0); // Down
    EXPECT_EQ(moves[5].size(), 0); // Left Down
    EXPECT_EQ(moves[6].size(), 0); // Left
    EXPECT_EQ(moves[7].size(), 0); // Left Up
}

TEST_F(ChessRulesTest, DISABLED_GenerateMovesForKing) {
    Point position = {4, 0};
    auto moves = rules.GenerateMoves(position, board);
    ASSERT_EQ(moves.size(), 7);
    EXPECT_EQ(moves[0].size(), 1); // Up
    EXPECT_EQ(moves[1].size(), 1); // Right Up
    EXPECT_EQ(moves[2].size(), 0); // Right
    EXPECT_EQ(moves[3].size(), 0); // Right Down
    EXPECT_EQ(moves[4].size(), 0); // Down
    EXPECT_EQ(moves[5].size(), 0); // Left Down
    EXPECT_EQ(moves[6].size(), 0); // Left
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}