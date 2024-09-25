#include <gtest/gtest.h>
#include "chessboard.hpp"
#include "chesspiece.hpp"


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
    // Check black king
    ChessPiece* blackKing = board->getPiece(Point(0, 4));
    ASSERT_NE(blackKing, nullptr);
    EXPECT_EQ(blackKing->getName(), "BK");
    EXPECT_FALSE(blackKing->getIsWhite());

    // Check black queen
    ChessPiece* blackQueen = board->getPiece(Point(0, 3));
    ASSERT_NE(blackQueen, nullptr);
    EXPECT_EQ(blackQueen->getName(), "BQ");
    EXPECT_FALSE(blackQueen->getIsWhite());

    // Check black knights
    ChessPiece* blackKnight1 = board->getPiece(Point(0, 1));
    ASSERT_NE(blackKnight1, nullptr);
    EXPECT_EQ(blackKnight1->getName(), "BN");
    EXPECT_FALSE(blackKnight1->getIsWhite());

    ChessPiece* blackKnight2 = board->getPiece(Point(0, 6));
    ASSERT_NE(blackKnight2, nullptr);
    EXPECT_EQ(blackKnight2->getName(), "BN");
    EXPECT_FALSE(blackKnight2->getIsWhite());

    // Check black bishops
    ChessPiece* blackBishop1 = board->getPiece(Point(0, 2));
    ASSERT_NE(blackBishop1, nullptr);
    EXPECT_EQ(blackBishop1->getName(), "BB");
    EXPECT_FALSE(blackBishop1->getIsWhite());

    ChessPiece* blackBishop2 = board->getPiece(Point(0, 5));
    ASSERT_NE(blackBishop2, nullptr);
    EXPECT_EQ(blackBishop2->getName(), "BB");
    EXPECT_FALSE(blackBishop2->getIsWhite());

    // Check black rooks
    ChessPiece* blackRook1 = board->getPiece(Point(0, 0));
    ASSERT_NE(blackRook1, nullptr);
    EXPECT_EQ(blackRook1->getName(), "BR");
    EXPECT_FALSE(blackRook1->getIsWhite());

    ChessPiece* blackRook2 = board->getPiece(Point(0, 7));
    ASSERT_NE(blackRook2, nullptr);
    EXPECT_EQ(blackRook2->getName(), "BR");
    EXPECT_FALSE(blackRook2->getIsWhite());

    // Check white king
    ChessPiece* whiteKing = board->getPiece(Point(7, 4));
    ASSERT_NE(whiteKing, nullptr);
    EXPECT_EQ(whiteKing->getName(), "WK");
    EXPECT_TRUE(whiteKing->getIsWhite());

    // Check white queen
    ChessPiece* whiteQueen = board->getPiece(Point(7, 3));
    ASSERT_NE(whiteQueen, nullptr);
    EXPECT_EQ(whiteQueen->getName(), "WQ");
    EXPECT_TRUE(whiteQueen->getIsWhite());

    // Check white knights
    ChessPiece* whiteKnight1 = board->getPiece(Point(7, 1));
    ASSERT_NE(whiteKnight1, nullptr);
    EXPECT_EQ(whiteKnight1->getName(), "WN");
    EXPECT_TRUE(whiteKnight1->getIsWhite());

    ChessPiece* whiteKnight2 = board->getPiece(Point(7, 6));
    ASSERT_NE(whiteKnight2, nullptr);
    EXPECT_EQ(whiteKnight2->getName(), "WN");
    EXPECT_TRUE(whiteKnight2->getIsWhite());

    // Check white bishops
    ChessPiece* whiteBishop1 = board->getPiece(Point(7, 2));
    ASSERT_NE(whiteBishop1, nullptr);
    EXPECT_EQ(whiteBishop1->getName(), "WB");
    EXPECT_TRUE(whiteBishop1->getIsWhite());

    ChessPiece* whiteBishop2 = board->getPiece(Point(7, 5));
    ASSERT_NE(whiteBishop2, nullptr);
    EXPECT_EQ(whiteBishop2->getName(), "WB");
    EXPECT_TRUE(whiteBishop2->getIsWhite());

    // Check white rooks
    ChessPiece* whiteRook1 = board->getPiece(Point(7, 0));
    ASSERT_NE(whiteRook1, nullptr);
    EXPECT_EQ(whiteRook1->getName(), "WR");
    EXPECT_TRUE(whiteRook1->getIsWhite());

    ChessPiece* whiteRook2 = board->getPiece(Point(7, 7));
    ASSERT_NE(whiteRook2, nullptr);
    EXPECT_EQ(whiteRook2->getName(), "WR");
    EXPECT_TRUE(whiteRook2->getIsWhite());


}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}