#include <gtest/gtest.h>
#include "chessrules.hpp"
#include "chessboard.hpp"
#include "gmock/gmock-matchers.h"
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
    std::map<std::string, Point> startingPositions;
    void SetUp() override {
       
        // Initialize the board with pieces for testing
       
       board.InitialiseBoard();
       startingPositions= initializeStartingPositions();       
    }

    void TearDown() override 
    {
        board.clearBoard();
    }
};

TEST_F(ChessRulesTest, GenerateMovesForPawn) {
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

TEST_F(ChessRulesTest, GenerateMovesForKnight1) {
    Point position = startingPositions["WN1"];
    auto moves = rules.GenerateMoves(position, board);
    //0,2
    //2,2
    //3,1

    ASSERT_EQ(moves.size(), 1);
    EXPECT_EQ(moves[0][0], Point(2, 2));
    EXPECT_EQ(moves[0][1], Point(3, 1));
    EXPECT_EQ(moves[0][2], Point(0, 2));

}

TEST_F(ChessRulesTest, GenerateMovesForKnight2) {
    Point position = startingPositions["WN2"];
    auto moves = rules.GenerateMoves(position, board);
    //7,2
    //4,1
    //5,2

    ASSERT_EQ(moves.size(), 1);
    EXPECT_EQ(moves[0][0], Point(7, 2));
    EXPECT_EQ(moves[0][1], Point(4, 1));
    EXPECT_EQ(moves[0][2], Point(5, 2));

}

TEST_F(ChessRulesTest, GenerateMovesForBishop) {
    Point position = startingPositions["WB1"];
    //(3, 1),(4, 2)(5, 3)(6, 4)(7, 5)(1, 1)(0, 2)
    auto moves = rules.GenerateMoves(position, board);
    ASSERT_EQ(moves.size(), 4);
    EXPECT_EQ(moves[0].size(), 5); // Right Up
    EXPECT_EQ(moves[1].size(), 0); // Right Down
    EXPECT_EQ(moves[2].size(), 0); // Left Down
    EXPECT_EQ(moves[3].size(), 2); // Left Up
    
    EXPECT_EQ(moves[0][0], Point(3, 1));
    EXPECT_EQ(moves[0][1], Point(4, 2));
    EXPECT_EQ(moves[0][2], Point(5, 3));
    EXPECT_EQ(moves[0][3], Point(6, 4));
    EXPECT_EQ(moves[0][4], Point(7, 5));

    EXPECT_EQ(moves[3][0], Point(1, 1));
    EXPECT_EQ(moves[3][1], Point(0, 2));
    
}

TEST_F(ChessRulesTest, GenerateMovesForQueen) {
        
        Point position = startingPositions["WQ"];
    
        std::vector<std::vector<Point>> expected = {
        { 
            Point(3, 1), Point(3, 2), Point(3, 3), 
            Point(3, 4), Point(3, 5), Point(3, 6), Point(3, 7) 
        },
        { Point(4, 1), Point(5, 2), Point(6, 3), Point(7, 4) },
        { Point(4, 0), Point(5, 0), Point(6, 0), Point(7, 0) },
        {},  // index: 3 (empty vector)
        {},  // index: 4 (empty vector)
        {},  // index: 5 (empty vector)
        { Point(2, 0), Point(1, 0), Point(0, 0) },
        { Point(2, 1), Point(1, 2), Point(0, 3) }
    };

    auto moves = rules.GenerateMoves(position, board);
    ASSERT_EQ(moves.size(), 8);

    for (size_t i = 0; i < moves.size(); i++)
        for (size_t j = 0; j < moves[i].size(); j++) {
            EXPECT_EQ(moves[i][j], expected[i][j]); // Compare individual Point objects
        }



 
}

TEST_F(ChessRulesTest, GenerateMovesForWhiteKing) {
    Point position = startingPositions["WK"];

  std::vector<std::vector<Point>> expected = {
        { Point(4, 1) },   // index: 0
        { Point(5, 1) },   // index: 1
        { Point(5, 0) },   // index: 2
        {},                 // index: 3 (empty vector)
        {},                 // index: 4 (empty vector)
        {},                 // index: 5 (empty vector)
        { Point(3, 0) },   // index: 6
        { Point(3, 1) }    // index: 7
    };

    auto moves = rules.GenerateMoves(position, board);
    ASSERT_EQ(moves.size(), 8);
    EXPECT_EQ(moves, expected);

}

TEST_F(ChessRulesTest, GenerateMovesForWhiteKingRandom) {

    board.movePiece(Point(4,0), Point(4,4));
    Point position = Point(4, 4);
    board.printBoard();

    
    std::vector<std::vector<Point>> expected = {
        { Point(3, 3) },
        { Point(3, 4) },
        { Point(3, 5) },
        { Point(4, 3) },
        { Point(4, 5) },
        { Point(5, 3) },
        { Point(5, 4) },
        { Point(5, 5) }
    };

    std::vector<Point> flattened_points_expected;
    for (const auto& row : expected) {
        flattened_points_expected.insert(flattened_points_expected.end(), row.begin(), row.end());
    }
    std::sort(flattened_points_expected.begin(), flattened_points_expected.end());



    auto moves = rules.GenerateMoves(position, board);
    ASSERT_EQ(moves.size(), 8);

    std::vector<Point> flattened_points_moves;
    for (const auto& row : moves) {
        flattened_points_moves.insert(flattened_points_moves.end(), row.begin(), row.end());
    }
    std::sort(flattened_points_moves.begin(), flattened_points_moves.end());


    EXPECT_EQ(flattened_points_moves, flattened_points_expected);
    EXPECT_EQ(flattened_points_expected, flattened_points_moves);

//   for (size_t i = 0; i < moves.size(); i++)
//         for (size_t j = 0; j < moves[i].size(); j++) {
//             EXPECT_EQ(moves[i][j], expected[i][j]); // Compare individual Point objects
//         }

//     EXPECT_EQ(moves, expected);

  
}

TEST_F(ChessRulesTest, GenerateMovesForWhiteKingVertex1) {

    Point position = Point(7, 7);
    board.movePiece(Point(4,0), position);
   
    board.printBoard();

    
    std::vector<std::vector<Point>> expected = {
        { Point(6, 6) },
        { Point(6, 7) },
        { Point(7, 6) }
    };

    std::vector<Point> flattened_points_expected;
    for (const auto& row : expected) {
        flattened_points_expected.insert(flattened_points_expected.end(), row.begin(), row.end());
    }
    std::sort(flattened_points_expected.begin(), flattened_points_expected.end());



    auto moves = rules.GenerateMoves(position, board);

    ASSERT_EQ(moves.size(), 8);

    std::vector<Point> flattened_points_moves;
    for (const auto& row : moves) {
        flattened_points_moves.insert(flattened_points_moves.end(), row.begin(), row.end());
    }
    std::sort(flattened_points_moves.begin(), flattened_points_moves.end());


    EXPECT_EQ(flattened_points_moves, flattened_points_expected);
    EXPECT_EQ(flattened_points_expected, flattened_points_moves);

  
}

TEST_F(ChessRulesTest, GenerateMovesForWhiteKingVertex2) {

    Point position = Point(0, 7);
    board.movePiece(Point(4,0), position);
   
    board.printBoard();

    
    std::vector<std::vector<Point>> expected = {
        { Point(0, 6) },
        { Point(1, 7) },
        { Point(1, 6) }
    };

    std::vector<Point> flattened_points_expected;
    for (const auto& row : expected) {
        flattened_points_expected.insert(flattened_points_expected.end(), row.begin(), row.end());
    }
    std::sort(flattened_points_expected.begin(), flattened_points_expected.end());



    auto moves = rules.GenerateMoves(position, board);

    ASSERT_EQ(moves.size(), 8);

    std::vector<Point> flattened_points_moves;
    for (const auto& row : moves) {
        flattened_points_moves.insert(flattened_points_moves.end(), row.begin(), row.end());
    }
    std::sort(flattened_points_moves.begin(), flattened_points_moves.end());


    EXPECT_EQ(flattened_points_moves, flattened_points_expected);
    EXPECT_EQ(flattened_points_expected, flattened_points_moves);

  
}

TEST_F(ChessRulesTest, GenerateMovesForWhiteKingVertex3) {

    Point position = Point(0, 0);
    board.movePiece(Point(4,0), position);
   
    board.printBoard();

    
    std::vector<std::vector<Point>> expected = {
        { Point(0, 1) },
        { Point(1, 1) },
        { Point(1, 0) }
    };

    std::vector<Point> flattened_points_expected;
    for (const auto& row : expected) {
        flattened_points_expected.insert(flattened_points_expected.end(), row.begin(), row.end());
    }
    std::sort(flattened_points_expected.begin(), flattened_points_expected.end());



    auto moves = rules.GenerateMoves(position, board);

    ASSERT_EQ(moves.size(), 8);

    std::vector<Point> flattened_points_moves;
    for (const auto& row : moves) {
        flattened_points_moves.insert(flattened_points_moves.end(), row.begin(), row.end());
    }
    std::sort(flattened_points_moves.begin(), flattened_points_moves.end());


    EXPECT_EQ(flattened_points_moves, flattened_points_expected);
    EXPECT_EQ(flattened_points_expected, flattened_points_moves);

  
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}