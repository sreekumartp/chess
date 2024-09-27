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

#define DEBUG 1

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
        if(y+n <= 8) 
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
        if(y-n > 0 ) 
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
        if(x-n > 0 ) 
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
        if(x+n <=8 ) 
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
        if(x-n > 0 && y+n <= 8) 
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
        if(x-n > 0 && y-n > 0 ) 
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
        if(x+n <= 8 && y+n <= 8) 
        {
            int new_x = x + n;
            int new_y = y + n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}


// Function to compute coordinates to the right and diagonally down of a given point
std::vector<Point> ChessRules::compute_coordinates_right_down(int x, int y, int max_n) {
    std::vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        //check if coordinates are withing the boundary and if so store the new coordinate
        if(x+n <= 8 && y-n >0 ) 
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
    if(new_x<=8 && new_y<=8)
    {
        moves.push_back(Point(new_x,new_y));
    }

  
    new_x = x+2, new_y=y+1;
    if(new_x<=8 && new_y<=8)
    {
        moves.push_back(Point(new_x,new_y));
    }



    new_x= x+2, new_y=y-1;
    if(new_x<=8 && new_y>=1)
    {
        moves.push_back(Point(new_x,new_y));
    }    
    new_x=x+1, new_y=y-2;
    if(new_x<=8 && new_y>=1)
    {
        moves.push_back(Point(new_x,new_y));
    }    
    new_x=x-2, new_y=y-1;
    if(new_x>=1 && new_y>=1)
    {
        moves.push_back(Point(new_x,new_y));
    }    
    new_x=x-1, new_y=y-2;
    if(new_x>=1 && new_y>=1)
    {
        moves.push_back(Point(new_x,new_y));
    }    
    new_x=x-2, new_y=y+1;
    if(new_x>=1 && new_y<=8)
    {
        moves.push_back(Point(new_x,new_y));
    }    
    new_x=x-1, new_y=y+2;
    if(new_x>=1 && new_y<=8)
    {
        moves.push_back(Point(new_x,new_y));
    }

    allmoves.push_back(moves);
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

        allmoves.push_back(compute_coordinates_right_up(x,y,8));
        allmoves.push_back(compute_coordinates_right_down(x,y,8));
        allmoves.push_back(compute_coordinates_left_down(x,y,8));
        allmoves.push_back(compute_coordinates_left_up(x,y,8));
        
        

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


        allmoves.push_back(compute_coordinates_up(x,y,8));
        allmoves.push_back(compute_coordinates_right_up(x,y,8));
        allmoves.push_back(compute_coordinates_right(x,y,8));
        allmoves.push_back(compute_coordinates_right_down(x,y,8));
        allmoves.push_back(compute_coordinates_down(x,y,8));
        allmoves.push_back(compute_coordinates_left_down(x,y,8));
        allmoves.push_back(compute_coordinates_left(x,y,8));
        allmoves.push_back(compute_coordinates_left_up(x,y,8));


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

       

        return allmoves;
    }

