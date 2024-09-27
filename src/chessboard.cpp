#include "chessboard.hpp"
#include "chesspiece.hpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <memory>

#include "pawn.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "rook.hpp"

#include <cassert>

// Constructor
Board::Board() {

    // Initialize the board with nullptr or appropriate ChessPiece objects
    std::for_each(board.begin(), board.end(), [](auto& row) {
        std::fill(row.begin(), row.end(), nullptr);
    });
}

// Destructor. Delete all the pieces on the board
Board::~Board() {
    
}

bool Board::InitialiseBoard() {


       // Create white pawns
    for (int col = 0; col < 8; ++col) {
        setPiece(std::make_unique<Pawn>("WP", true, Point(col, 1)));
    }
  
    // Create white king
    setPiece(std::make_unique<King>("WK", true, Point(4, 0)));
    // Create white queen
    setPiece(std::make_unique<Queen>("WQ", true, Point(3, 0)));
    // Create white knight
    setPiece(std::make_unique<Knight>("WN", true, Point(1, 0)));
    setPiece(std::make_unique<Knight>("WN", true, Point(6, 0)));
    // Create white bishop
    setPiece(std::make_unique<Bishop>("WB", true, Point(2, 0)));
    setPiece(std::make_unique<Bishop>("WB", true, Point(5, 0)));   
    // Create white rook
    setPiece(std::make_unique<Rook>("WR", true, Point(0, 0)));
    setPiece(std::make_unique<Rook>("WR", true, Point(7, 0)));


    // Create black pawns
    for (int col = 0; col < 8; ++col) {
        setPiece(std::make_unique<Pawn>("BP", false, Point(col, 6)));
    }

    // Create black bishop
    setPiece(std::make_unique<Bishop>("BB", false, Point(2, 7)));
    setPiece(std::make_unique<Bishop>("BB", false, Point(5, 7)));


    //Create black knight
    setPiece(std::make_unique<Knight>("BN", false, Point(1, 7)));
    setPiece(std::make_unique<Knight>("BN", false, Point(6, 7)));
    //Create black rook
    setPiece(std::make_unique<Rook>("BR", false, Point(0, 7)));
    setPiece(std::make_unique<Rook>("BR", false, Point(7, 7)));

    //Create black queen
    setPiece(std::make_unique<Queen>("BQ", false, Point(3, 7)));

    //Create black king
    setPiece(std::make_unique<King>("BK", false, Point(4, 7)));

    
    return true;
}
void Board::printBoard() const {
    Point pt(1,1);

    for (int row = 7; row >=0 ; row--) {
    for (int col = 0; col < 8; col++) {
            ChessPiece* cp = board[col][row].get();

            if (cp) {
                pt = cp->getPosition();
                std::cout << cp->getName() <<'[' << col << ',' << row <<']' <<' ';
            } else {
                std::cout << "__" << ' ';
            }
        }
        std::cout << std::endl;
    }
#if 0
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            ChessPiece* cp = board[row][col].get();

            if (cp) {
                pt = cp->getPosition();
                // std::cout << cp->getName() << ',' << (cp->getIsWhite() ? "White" : "Black")
                //                     << ',' << '[' << pt.x << ',' << pt.y << ']' << " ";
                std::cout << cp->getName() << ' ';
            } else {
                std::cout << "__" << ' ';
            }
        }
        std::cout << std::endl;
    }
    #endif
}





// Return the pointer to the piece object stored at the location
ChessPiece* Board::getPiece(Point position) const {
    int x = position.x;
    int y = position.y;
    ChessPiece *piecePtr = board[x][y].get();
    // if (piecePtr) {
    //     std::cout << "Piece at (" << x << ", " << y << "): "
    //               << piecePtr->getName() << ", "
    //               << (piecePtr->getIsWhite() ? "White" : "Black") << ", "
    //               << "Position: [" << piecePtr->getPosition().x << ", " << piecePtr->getPosition().y << "]"
    //               << std::endl;
    // } else {
    //     std::cout << "No piece at (" << x << ", " << y << ")" << std::endl;
    // }
    return board[x][y].get();
}

void Board::setPiece(std::unique_ptr<ChessPiece> piece) {

    int x = piece->getPosition().x;
    int y = piece->getPosition().y;

    assert(x >= 0 && x < 8);
    assert(y >= 0 && y < 8);

    board[x][y] = std::move(piece);
}

void Board::movePiece(Point start, Point end) {
    std::unique_ptr<ChessPiece> piece;
    piece = std::move(board[start.x][start.y]);

    board[end.x][end.y] = std::move(piece);
    board[start.x][start.y] = nullptr;
}


void Board::clearBoard()
{

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
                board[row][col].reset();
        }
    }

}

