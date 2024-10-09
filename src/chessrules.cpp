/**
 * @file chessrules.cpp
 * @brief Implementation of chess rules and move generation for different chess pieces.
 * 
 * This file contains the implementation of the ChessRules class, which provides methods
 * to generate possible moves for different chess pieces based on their positions on the board.
 * It also includes helper functions to compute coordinates for various directions.
 * 
 * @include <vector>
 * @include "chessrules.hpp"
 * @include "chessboard.hpp"
 * @include "common.hpp"
 * @include "chesspiece.hpp"
 * @include "pawn.hpp"
 * @include "rook.hpp"
 * @include "knight.hpp"
 * @include "bishop.hpp"
 * @include "queen.hpp"
 * @include "king.hpp"
 * @include <iostream>
 * 
 * @define DEBUG 0
 * 
 * @class ChessRules
 * @brief Class to handle chess rules and move generation.
 * 
 * @fn std::vector<std::vector<Point>> ChessRules::GenerateMoves(Point position, const Board & board)
 * @brief Generates all possible moves for a piece at a given position on the board.
 * @param position The position of the piece on the board.
 * @param board The current state of the chess board.
 * @return A vector of vectors containing possible moves for the piece.
 * 
 * @fn bool ChessRules::IsValidMove(Point start, Point end, const Board & board)
 * @brief Checks if a move from start to end position is valid.
 * @param start The starting position of the move.
 * @param end The ending position of the move.
 * @param board The current state of the chess board.
 * @return True if the move is valid, false otherwise.
 * 
 * @fn std::vector<Point> ChessRules::compute_coordinates_up(int x, int y, int max_n)
 * @brief Computes coordinates vertically up from a given point.
 * @param x The x-coordinate of the starting point.
 * @param y The y-coordinate of the starting point.
 * @param max_n The maximum number of steps to move.
 * @return A vector of points representing the coordinates.
 * 
 * @fn std::vector<Point> ChessRules::compute_coordinates_down(int x, int y, int max_n)
 * @brief Computes coordinates vertically down from a given point.
 * @param x The x-coordinate of the starting point.
 * @param y The y-coordinate of the starting point.
 * @param max_n The maximum number of steps to move.
 * @return A vector of points representing the coordinates.
 * 
 * @fn std::vector<Point> ChessRules::compute_coordinates_left(int x, int y, int max_n)
 * @brief Computes coordinates horizontally left from a given point.
 * @param x The x-coordinate of the starting point.
 * @param y The y-coordinate of the starting point.
 * @param max_n The maximum number of steps to move.
 * @return A vector of points representing the coordinates.
 * 
 * @fn std::vector<Point> ChessRules::compute_coordinates_right(int x, int y, int max_n)
 * @brief Computes coordinates horizontally right from a given point.
 * @param x The x-coordinate of the starting point.
 * @param y The y-coordinate of the starting point.
 * @param max_n The maximum number of steps to move.
 * @return A vector of points representing the coordinates.
 * 
 * @fn std::vector<Point> ChessRules::compute_coordinates_left_up(int x, int y, int max_n)
 * @brief Computes coordinates diagonally left up from a given point.
 * @param x The x-coordinate of the starting point.
 * @param y The y-coordinate of the starting point.
 * @param max_n The maximum number of steps to move.
 * @return A vector of points representing the coordinates.
 * 
 * @fn std::vector<Point> ChessRules::compute_coordinates_left_down(int x, int y, int max_n)
 * @brief Computes coordinates diagonally left down from a given point.
 * @param x The x-coordinate of the starting point.
 * @param y The y-coordinate of the starting point.
 * @param max_n The maximum number of steps to move.
 * @return A vector of points representing the coordinates.
 * 
 * @fn std::vector<Point> ChessRules::compute_coordinates_right_up(int x, int y, int max_n)
 * @brief Computes coordinates diagonally right up from a given point.
 * @param x The x-coordinate of the starting point.
 * @param y The y-coordinate of the starting point.
 * @param max_n The maximum number of steps to move.
 * @return A vector of points representing the coordinates.
 * 
 * @fn std::vector<Point> ChessRules::compute_coordinates_right_down(int x, int y, int max_n)
 * @brief Computes coordinates diagonally right down from a given point.
 * @param x The x-coordinate of the starting point.
 * @param y The y-coordinate of the starting point.
 * @param max_n The maximum number of steps to move.
 * @return A vector of points representing the coordinates.
 * 
 * @fn std::vector<std::vector<Point>> ChessRules::compute_knights_moves(int x, int y, int max_n, bool isWhite)
 * @brief Computes possible moves for a knight from a given position.
 * @param x The x-coordinate of the starting position.
 * @param y The y-coordinate of the starting position.
 * @param max_n The maximum number of steps to move.
 * @param isWhite Boolean indicating if the knight is white.
 * @return A vector of vectors containing possible moves for the knight.
 * 
 * @fn std::vector<std::vector<Point>> ChessRules::compute_pawn_moves(int x, int y, int max_n, bool isWhite)
 * @brief Computes possible moves for a pawn from a given position.
 * @param x The x-coordinate of the starting position.
 * @param y The y-coordinate of the starting position.
 * @param max_n The maximum number of steps to move.
 * @param isWhite Boolean indicating if the pawn is white.
 * @return A vector of vectors containing possible moves for the pawn.
 * 
 * @fn std::vector<std::vector<Point>> ChessRules::compute_bishop_moves(int x, int y, int max_n, bool isWhite)
 * @brief Computes possible moves for a bishop from a given position.
 * @param x The x-coordinate of the starting position.
 * @param y The y-coordinate of the starting position.
 * @param max_n The maximum number of steps to move.
 * @param isWhite Boolean indicating if the bishop is white.
 * @return A vector of vectors containing possible moves for the bishop.
 * 
 * @fn std::vector<std::vector<Point>> ChessRules::compute_rook_moves(int x, int y, int max_n, bool isWhite)
 * @brief Computes possible moves for a rook from a given position.
 * @param x The x-coordinate of the starting position.
 * @param y The y-coordinate of the starting position.
 * @param max_n The maximum number of steps to move.
 * @param isWhite Boolean indicating if the rook is white.
 * @return A vector of vectors containing possible moves for the rook.
 * 
 * @fn std::vector<std::vector<Point>> ChessRules::compute_queen_moves(int x, int y, int max_n, bool isWhite)
 * @brief Computes possible moves for a queen from a given position.
 * @param x The x-coordinate of the starting position.
 * @param y The y-coordinate of the starting position.
 * @param max_n The maximum number of steps to move.
 * @param isWhite Boolean indicating if the queen is white.
 * @return A vector of vectors containing possible moves for the queen.
 * 
 * @fn std::vector<std::vector<Point>> ChessRules::compute_king_moves(int x, int y, int max_n, bool isWhite)
 * @brief Computes possible moves for a king from a given position.
 * @param x The x-coordinate of the starting position.
 * @param y The y-coordinate of the starting position.
 * @param max_n The maximum number of steps to move.
 * @param isWhite Boolean indicating if the king is white.
 * @return A vector of vectors containing possible moves for the king.
 */
#include <vector>
#include "chessrules.hpp"
#include "chessboard.hpp"
#include "common.hpp"
#include "chesspiece.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"
#include <iostream>

#define DEBUG 0

std::vector<Point> ChessRules::GenerateValidMoves(Point position, const Board & board)
{

std:: vector<Point> validMoves;

validMoves.reserve(8);
ChessPiece* piecePtr= board.getPiece(position);
if (piecePtr == nullptr) {
    std::cerr << "Error: No piece found at position (" << position.x << ", " << position.y << ")" << std::endl;
    return {};
}

    // compute the valid moves for a pawn
    if(dynamic_cast<Pawn *>(piecePtr))
    {
        // compute the valid move for a white pawn

        if(piecePtr->getIsWhite())
        {
            std::cout << "Generating valid moves for Pawn at position (" << position.x << ", " << position.y << ")" <<' ' <<piecePtr->getName() <<std::endl;
            // ... generate Pawn-specific moves
            validMoves = compute_pawn_valid_moves(position.x, position.y, 2,true, board);
        }
        else
        {
        // compute the valid move for a black pawn
        
        
        }

        
    }

return validMoves;
}

// Function to compute the possible moves of a pawn
std::vector<Point> ChessRules::compute_pawn_valid_moves(int x, int y, int max_n,bool isWhite,const Board & board)
{
  
    std::vector<Point> validMoves;
    int maxn = 2;
     
    validMoves.reserve(4);
    // compute valid moves in forward (up) direction
    // if piece on starting position , then it can jump two positions
    if(y==1)
    {
        maxn = 2;

        // check if in each position in front of the pawn is empty
        for (int n = 1; n <= maxn; ++n) {
            // retrieve the piece at the position (x, y+n) and check if empty
            if(board.getPiece({x, y+n}) == nullptr)
            {
                int new_x = x;
                int new_y = y + n;
                validMoves.push_back({new_x, new_y});
            }
            else
            {
                // no more moves possible
                // break out of the loop

                break;
            }

        }

    }
    else{
        // if piece is not on starting position , then it can jump one position

        maxn = 1;
        // check if in each position in front of the pawn is empty
        for (int n = 1; n <= maxn; ++n) {
            
            if(y+n <=7)
            {
                    // retrieve the piece at the position (x, y+n) and check if empty
                    if(board.getPiece({x, y+n}) == nullptr)
                    {
                        int new_x = x;
                        int new_y = y + n;
                        validMoves.push_back({new_x, new_y});
                    }
                    else
                    {
                        // no more moves possible
                        // break out of the loop

                        break;
                    }
            }

        }

    }

    // compute valid moves in forward (up, right diagonal) direction

        if(x+1 <= 7 && y+1 <= 7)
        {
            // retrieve the piece at the position (x+n, y+n) and check if it is an opponent piece
            ChessPiece* piecePtr = board.getPiece({x+1, y+1});
            if (piecePtr != nullptr && piecePtr->getIsWhite() != isWhite) {
                int new_x = x + 1;
                int new_y = y + 1;
                validMoves.push_back({new_x, new_y});
            }
            else{
                std::cout << "friend found at position (" << x << ", " << y << ")" << std::endl;

            }
        }
    


    // compute valid moves forward (up, left diagonal direction )

    if(x-1 >=0 && y+1 <= 7)
    {
        // retrieve the piece at the position (x-n, y+n) and check if it is an opponent piece
        ChessPiece* piecePtr = board.getPiece({x-1, y+1});
        if (piecePtr != nullptr && piecePtr->getIsWhite() != isWhite) {
            int new_x = x - 1;
            int new_y = y + 1;
            validMoves.push_back({new_x, new_y});
        }
        else{
            std::cout << "friend found at position (" << x << ", " << y << ")" << std::endl;

        }
    }   

    return validMoves;
}




std::vector<std:: vector<Point>> ChessRules:: GenerateMoves(Point position, const Board & board)
{

    ChessPiece* piecePtr= board.getPiece(position);
    if (piecePtr == nullptr) {
        std::cerr << "Error: No piece found at position (" << position.x << ", " << position.y << ")" << std::endl;
        return {};
    }
    std::vector<std::vector<Point>> allmoves;
        
    allmoves.reserve(8);


    /* TODO:  Is this a good design choice ? Piece type could be an attribute of the piece class.
        Will there be a performance impact if we use dynamic_cast to check the type of the piece (RTTI) ?
    */

    if (dynamic_cast<Pawn*>(piecePtr)) {

        // It's a Pawn
        bool isWhite = piecePtr->getIsWhite();

        std::cout << "Generating moves for Pawn at position (" << position.x << ", " << position.y << ")" <<' ' <<piecePtr->getName() <<std::endl;
        // ... generate Pawn-specific moves
        allmoves = compute_pawn_moves(position.x, position.y, 2,isWhite);

    } else if (dynamic_cast<Rook*>(piecePtr)) {
        // It's a Rook
         bool isWhite = piecePtr->getIsWhite();
        // ... generate Rook-specific moves
        std::cout << "Generating moves for Rook at position (" << position.x << ", " << position.y << ")" <<' ' <<piecePtr->getName() <<std::endl;
        allmoves=compute_rook_moves(position.x, position.y, 8,isWhite);

    } else if (dynamic_cast<Knight*>(piecePtr)) {
        // Its a Knight
         bool isWhite = piecePtr->getIsWhite();
        std::cout << "Generating moves for Knight at position (" << position.x << ", " << position.y << ")" <<' ' <<piecePtr->getName() <<std::endl;
        allmoves=compute_knights_moves(position.x, position.y, 1,isWhite);
    } 
    else if(dynamic_cast<Bishop*>(piecePtr))
    {
        // Its a Bishop
         bool isWhite = piecePtr->getIsWhite();
        std::cout << "Generating moves for Bishop at position (" << position.x << ", " << position.y << ")" <<' ' <<piecePtr->getName() <<std::endl;
        allmoves=compute_bishop_moves(position.x, position.y, 8,isWhite);
    }
    else if(dynamic_cast<Queen*>(piecePtr))
    {
        // Its a Queen
         bool isWhite = piecePtr->getIsWhite();
        std::cout << "Generating moves for Queen at position (" << position.x << ", " << position.y << ")" <<' ' <<piecePtr->getName() <<std::endl;
        allmoves=compute_queen_moves(position.x, position.y, 8,isWhite);
    }
    else if(dynamic_cast<King*>(piecePtr))
    {
        // Its a King
         bool isWhite = piecePtr->getIsWhite();
        std::cout << "Generating moves for King at position (" << position.x << ", " << position.y << ")" <<' ' <<piecePtr->getName() <<std::endl;
        allmoves=compute_king_moves(position.x, position.y, 1,isWhite);
    }
    else {
        // Handle the case where the piece type is unknown or unexpected
        // Log an error message / throw an exception
        std::cerr << "Error: Unknown piece type at position (" << position.x << ", " << position.y << ")" << std::endl;
    }

#if DEBUG
    std::cout << "size of allmoves is " << allmoves.size() << std::endl;

    for (const auto& moveSet : allmoves) {
        for (const auto& move : moveSet) {
            std::cout << "(" << move.x << ", " << move.y << ") ";
        }
        std::cout << std::endl;
    }
    // std::cout << allmoves[0][0].x <<','<<allmoves[0][1].y<<std::endl;
 #endif   
    return allmoves;
}

bool ChessRules::IsValidMove(Point start, Point end, const Board & board)
{
    
    return false;
};

// Function to compute coordinates vertically up of a given point
std::vector<Point> ChessRules::compute_coordinates_up(int x, int y, int max_n) {
    std::vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(y+n <= 7) 
        {
            int new_x = x;
            int new_y = y + n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}

// Function to compute coordinates vertically down of a given point
std::vector<Point> ChessRules::compute_coordinates_down(int x, int y, int max_n) {
    std::vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(y-n >= 0 ) 
        {
            int new_x = x;
            int new_y = y - n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}


// Function to compute coordinates horiz left of a given point
std::vector<Point> ChessRules::compute_coordinates_left(int x, int y, int max_n) {
    std::vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(x-n >=0 ) 
        {
            int new_x = x-n;
            int new_y = y;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}

// Function to compute coordinates horiz right of a given point
std::vector<Point> ChessRules::compute_coordinates_right(int x, int y, int max_n) {
    std::vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(x+n <=7 ) 
        {
            int new_x = x+n;
            int new_y = y;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}


// Function to compute coordinates to the right and diagonaly up of a given point
std::vector<Point> ChessRules::compute_coordinates_left_up(int x, int y, int max_n) {
    std::vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(x-n >= 0 && y+n <= 7) 
        {
            int new_x = x - n;
            int new_y = y + n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}


// Function to compute coordinates to the right and diagonaly up of a given point
std::vector<Point> ChessRules::compute_coordinates_left_down(int x, int y, int max_n) {
    std::vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(x-n >=0 && y-n >=0 ) 
        {
            int new_x = x - n;
            int new_y = y - n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}


// Function to compute coordinates to the left and diagonaly up of a given point
std::vector<Point> ChessRules::compute_coordinates_right_up(int x, int y, int max_n) {
    std::vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(x+n <= 7 && y+n <= 7) 
        {
            int new_x = x + n;
            int new_y = y + n;
            coordinates.push_back({new_x, new_y});
        }
    }
#if DEBUG    
    for (const auto& point : coordinates) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;
#endif
    return coordinates;
}


// Function to compute coordinates to the right and diagonally down of a given point
std::vector<Point> ChessRules::compute_coordinates_right_down(int x, int y, int max_n) {
    std::vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        //check if coordinates are withing the boundary and if so store the new coordinate
        if(x+n <= 7 && y-n >=0 ) 
        {
            int new_x = x + n;
            int new_y = y - n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}


std::vector<std::vector<Point>> ChessRules::compute_knights_moves(int x, int y, int max_n,bool isWhite) {
    
    std::vector<Point> moves;

    std::vector<std::vector<Point>> allmoves;
    
    int new_x=0;
    int new_y=0;

    new_x = x+1, new_y=y+2;
    if(new_x<=7 && new_y<=7)
    {
        moves.push_back(Point(new_x,new_y));
                std::cout << "Knight move: (" << new_x << ", " << new_y << ")" << std::endl;
    }

  
    new_x = x+2, new_y=y+1;
    if(new_x<=7 && new_y<=7)
    {
        moves.push_back(Point(new_x,new_y));
                std::cout << "Knight move: (" << new_x << ", " << new_y << ")" << std::endl;
    }



    new_x= x+2, new_y=y-1;
    if(new_x<=7 && new_y>=0)
    {
        moves.push_back(Point(new_x,new_y));
                std::cout << "Knight move: (" << new_x << ", " << new_y << ")" << std::endl;
    }    
    new_x=x+1, new_y=y-2;
    if(new_x<=7 && new_y>=0)
    {
        moves.push_back(Point(new_x,new_y));
                std::cout << "Knight move: (" << new_x << ", " << new_y << ")" << std::endl;
    }    
    new_x=x-2, new_y=y-1;
    if(new_x>=0 && new_y>=0)
    {
        moves.push_back(Point(new_x,new_y));
            std::cout << "Knight move: (" << new_x << ", " << new_y << ")" << std::endl;
    }    
    new_x=x-1, new_y=y-2;
    if(new_x>=0 && new_y>=0)
    {
        moves.push_back(Point(new_x,new_y));
         std::cout << "Knight move: (" << new_x << ", " << new_y << ")" << std::endl;
    }    
    new_x=x-2, new_y=y+1;
    if(new_x>=0 && new_y<=7)
    {
        moves.push_back(Point(new_x,new_y));
        std::cout << "Knight move: (" << new_x << ", " << new_y << ")" << std::endl;
    }    
    new_x=x-1, new_y=y+2;
    if(new_x>=0 && new_y<=7)
    {
        moves.push_back(Point(new_x,new_y));
        std::cout << "Knight move: (" << new_x << ", " << new_y << ")" << std::endl;
    }

    allmoves.push_back(moves);
    for (const auto& moveSet : allmoves) {
        for (const auto& move : moveSet) {
            std::cout << "(" << move.x << ", " << move.y << ") ";
        }
        std::cout << std::endl;
    }
    return allmoves;
}

    // Function to compute the possible moves of a pawn
    std::vector<std::vector<Point>> ChessRules::compute_pawn_moves(int x, int y, int max_n,bool isWhite)
    {
        std::vector<std::vector<Point>> allmoves;
        
        allmoves.reserve(3);

        //Whites are initialised from row 0 and row 1
        //Black are initialised from row 6 and row 7

        if(isWhite)  // WHITE PAWN
        {
            // if the white pawn is at the starting location , it can move 1 or 2 locations
            if(y==1)  //TODO : change 1 to a preprocesser macro
            {
               allmoves.push_back( compute_coordinates_up(x, y, 2));
                
            }
            else{ // piece is white and not on starting position
                // move one location
                allmoves.push_back( compute_coordinates_up(x, y, 1));            
            }
#if 0
//TODO: constraining the moves as per board layout should be done outside this method
            //if there is a black piece diagonally one place up left or right, it can move to that position by capturing the piece
            if(isNotOnEdge(x,y))
            {
            //check if there is a black piece diagonally up left or right    
            ChessPiece* piecePtr= board.getPiece({x+1,y+1});
                if (piecePtr != nullptr && piecePtr->getIsWhite() == false)
                {
                    moves.push_back(Point(x+1,y+1));
                    allmoves.push_back(moves);
                    moves.clear();
                }
                piecePtr= board.getPiece({x-1,y+1});
                if (piecePtr != nullptr && piecePtr->getIsWhite() == false)
                {
                    moves.push_back(Point(x-1,y+1));
                    allmoves.push_back(moves);
                    moves.clear();
                }
            }
#endif
        }
        else // piece is black
        {
            //black pawn on starting position, it can move either 1 or 2 positions
            if(y==6)
            {
                allmoves.push_back(compute_coordinates_down(x,y,2));

            }
            else  //black pawn can move only one position
            {
                allmoves.push_back(compute_coordinates_down(x,y,1));    
          
            }

                //if there is a white piece diagonally one place up left or right, it can move to that position by capturing the piece
#if 0
                if(isNotOnEdge(x,y))
                {
                //check if there is a white piece diagonally down left or right    
                ChessPiece* piecePtr= board.getPiece({x-1,y-1});
                    if (piecePtr != nullptr && piecePtr->getIsWhite() == true)
                    {
                        moves.push_back(Point(x-1,y-1));
                        allmoves.push_back(moves);
                        moves.clear();
                    }
                    piecePtr= board.getPiece({x+1,y-1});
                    if (piecePtr != nullptr && piecePtr->getIsWhite() == true)
                    {
                        moves.push_back(Point(x+1,y-1));
                        allmoves.push_back(moves);
                        moves.clear();
                    }
                }
#endif    
        }

        return allmoves;

    }
    
    // Function to compute the possible moves of a bishop
    std::vector<std::vector<Point>> ChessRules::compute_bishop_moves(int x, int y, int max_n,bool isWhite)
    {
        
        //TODO: consider array for performance
        std::vector<std::vector<Point>> allmoves;
        
        allmoves.reserve(4);

        allmoves.push_back(compute_coordinates_right_up(x,y,7));
        allmoves.push_back(compute_coordinates_right_down(x,y,7));
        allmoves.push_back(compute_coordinates_left_down(x,y,7));
        allmoves.push_back(compute_coordinates_left_up(x,y,7));
        
        

        return allmoves;


    }
    
    // Function to compute the possible moves of a rook
    std::vector<std::vector<Point>> ChessRules::compute_rook_moves(int x, int y, int max_n,bool isWhite)
    {
        std::vector<std::vector<Point>> allmoves;
       
        allmoves.push_back(compute_coordinates_up(x,y,7));
        allmoves.push_back(compute_coordinates_right(x,y,7));
        allmoves.push_back(compute_coordinates_down(x,y,7));
        allmoves.push_back(compute_coordinates_left(x,y,7));

#if DEBUG
    std::cout << "size of allmoves is " << allmoves.size() << std::endl;

    for (const auto& moveSet : allmoves) {
        for (const auto& move : moveSet) {
            std::cout << "(" << move.x << ", " << move.y << ") ";
        }
        std::cout << std::endl;
    }
    // std::cout << allmoves[0][0].x <<','<<allmoves[0][1].y<<std::endl;
 #endif  
        return allmoves;
    }
    
    // Function to compute the possible moves of a queen
    std::vector<std::vector<Point>> ChessRules::compute_queen_moves(int x, int y, int max_n,bool isWhite)
    {
         std::vector<std::vector<Point>> allmoves;


        allmoves.push_back(compute_coordinates_up(x,y,7));
        allmoves.push_back(compute_coordinates_right_up(x,y,7));
        allmoves.push_back(compute_coordinates_right(x,y,7));
        allmoves.push_back(compute_coordinates_right_down(x,y,7));
        allmoves.push_back(compute_coordinates_down(x,y,7));
        allmoves.push_back(compute_coordinates_left_down(x,y,7));
        allmoves.push_back(compute_coordinates_left(x,y,7));
        allmoves.push_back(compute_coordinates_left_up(x,y,7));

        #if DEBUG
            std::cout << "size of allmoves is " << allmoves.size() << std::endl;
            int i =0;
            for (const auto& moveSet : allmoves) {
                std::cout << "index: " << i++ << " ";
                for (const auto& move : moveSet) {
                    std::cout << "(" << move.x << ", " << move.y << ") ";
                }
                std::cout << std::endl;
            }
        #endif

        return allmoves;;        

    }
    
    // Function to compute the possible moves of a king
   std::vector<std::vector<Point>> ChessRules::compute_king_moves(int x, int y, int max_n,bool isWhite)
    {
        //TODO: add diagonal moves for capture when a piece is present

        std::vector<std::vector<Point>> allmoves;     
        
        
        allmoves.push_back(compute_coordinates_up(x,y,1));
        allmoves.push_back(compute_coordinates_right_up(x,y,1));
        allmoves.push_back(compute_coordinates_right(x,y,1));
        allmoves.push_back(compute_coordinates_right_down(x,y,1));
        allmoves.push_back(compute_coordinates_down(x,y,1));
        allmoves.push_back(compute_coordinates_left_down(x,y,1));
        allmoves.push_back(compute_coordinates_left(x,y,1));
        allmoves.push_back(compute_coordinates_left_up(x,y,1));

    #if DEBUG
        std::cout << "size of allmovesking is " << allmoves.size() << std::endl;
        int i =0;
        for (const auto& moveSet : allmoves) {
            std::cout << "index: " << i++ << " ";
        for (const auto& move : moveSet) {
            std::cout << "(" << move.x << ", " << move.y << ") ";
        }
        std::cout << std::endl;
        }
    #endif
       

        return allmoves;
    }

