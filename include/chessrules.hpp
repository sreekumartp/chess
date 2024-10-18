#ifndef CHESSRULES_H
#define CHESSRULES_H

#include <vector>
#include "chessboard.hpp"
#include "common.hpp"


class ChessRules{
private:

enum class Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    DIAG_RIGHT_UP,
    DIAG_RIGHT_DOWN,
    DIAG_LEFT_UP,
    DIAG_LEFT_DOWN
};

public:

    std::vector<std:: vector<Point>> GenerateMoves(Point position, const Board & board);
    std::vector<Point> GenerateValidMoves(Point position, const Board & board);

    bool IsValidMove(Point start, Point end, const Board & board);

private:    

    void AddValidKnightMove(int x, int y, int new_x,int new_y,std::vector<Point>& moves,const Board & board);
    void AddValidRookMoves(int x, int y, Direction direction, std::vector<Point>& moves, const Board & board);
    void AddValidQueenMoves(int x, int y, Direction direction, std::vector<Point>& moves, const Board & board);


    // Function to compute coordinates vertically up of a given point
    std::vector<Point> compute_coordinates_up(int x, int y, int max_n);
    // Function to compute coordinates vertically down of a given point
    std::vector<Point> compute_coordinates_down(int x, int y, int max_n);
    // Function to compute coordinates horiz left of a given point
    std::vector<Point> compute_coordinates_left(int x, int y, int max_n);
    // Function to compute coordinates horiz right of a given point
    std::vector<Point> compute_coordinates_right(int x, int y, int max_n);
    // Function to compute coordinates to the right and diagonaly up of a given point
    std::vector<Point> compute_coordinates_left_up(int x, int y, int max_n); 
    // Function to compute coordinates to the right and diagonaly up of a given point
    std::vector<Point> compute_coordinates_left_down(int x, int y, int max_n);
    // Function to compute coordinates to the left and diagonaly up of a given point
    std::vector<Point> compute_coordinates_right_up(int x, int y, int max_n);
    // Function to compute coordinates to the right and diagonally down of a given point
    std::vector<Point> compute_coordinates_right_down(int x, int y, int max_n);
    // Function to compute the possible moves of a knight
    std::vector<std::vector<Point>> compute_knights_moves(int x, int y, int max_n,bool isWhite);
    // Function to compute the valid moves of a knight
    std::vector<Point> compute_knight_valid_moves(int x, int y, int max_n,bool isWhite,const Board & board);
        
    // Function to compute the possible moves of a pawn
    std::vector<std::vector<Point>>  compute_pawn_moves(int x, int y, int max_n,bool isWhite);
    // Function to compute the valid moves of a pawn
    std::vector<Point> compute_pawn_valid_moves(int x, int y, int max_n,bool isWhite,const Board & board);    
    
    // Function to compute the possible moves of a bishop
    std::vector<std::vector<Point>> compute_bishop_moves(int x, int y, int max_n,bool isWhite);
    // Function to generate valid moves for bishop
    std::vector<Point> compute_bishop_valid_moves(int x, int y, int max_n,bool isWhite,const Board & board);

    // Function to compute the possible moves of a rook
    std::vector<std::vector<Point>> compute_rook_moves(int x, int y, int max_n,bool isWhite);

    // Function to compute the possible moves of a rook
    std::vector<Point> compute_rook_valid_moves(int x, int y, int max_n,bool isWhite,const Board & board);

    // Function to compute the possible moves of a queen
    std::vector<std::vector<Point>>compute_queen_moves(int x, int y, int max_n,bool isWhite);
    std::vector<Point> compute_queen_valid_moves(int x, int y, int max_n,bool isWhite,const Board & board);
 


    // Function to compute the possible moves of a king
    std::vector<std::vector<Point>> compute_king_moves(int x, int y, int max_n,bool isWhite);
};

#endif // MAIN_H