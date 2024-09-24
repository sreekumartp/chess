#include <gtest/gtest.h>
#include "chessboard.h"
#include "chesspiece.h"


class ChessBoardTest : public ::testing::Test {
protected:
    void SetUp() override {
        board = std::make_unique<Board>();
    }

    std::unique_ptr<Board> board;
};

TEST_F(ChessBoardTest, InitialiseBoard) {
    ASSERT_TRUE(board->InitialiseBoard());

    // Check black pawns
    for (int col = 0; col < 8; ++col) {
        ChessPiece* piece = board->getPiece(Point(1, col));
        ASSERT_NE(piece, nullptr);
        EXPECT_EQ(piece->getName(), "BP");
        EXPECT_FALSE(piece->getIsWhite());
    }

    // Check white pawns
    for (int col = 0; col < 8; ++col) {
        ChessPiece* piece = board->getPiece(Point(6, col));
        ASSERT_NE(piece, nullptr);
        EXPECT_EQ(piece->getName(), "WP");
        EXPECT_TRUE(piece->getIsWhite());
    }

    // Add more checks for other pieces (king, queen, knight, bishop, rook) once they are implemented
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}