#include "chessboard.h"
#include "chesspiece.h"
#include <array>
#include <iostream>
#include <memory>

#include "pawn.h"
#include <cassert>

// Constructor
Board::Board() {

    // Initialize the board with nullptr or appropriate ChessPiece objects
    for (auto& row : board) {
        for (auto& cell : row) {
            cell = nullptr;
        }
    }



}

// Destructor. Delete all the pieces on the board
Board::~Board() {
    
}

bool Board::InitialiseBoard() {


       // Create black pawns
    for (int col = 0; col < 8; ++col) {
        //Pawn* pawn = new Pawn("Black Pawn", false, Point(1, col));
        //ChessPiece* piece = static_cast<ChessPiece*>(pawn);  // Explicit conversion
        setPiece(std::make_unique<Pawn>("BP", false, Point(1, col)));
    }
    

    // Create white pawns
    for (int col = 0; col < 8; ++col) {
        //Pawn* pawn = new Pawn("Black Pawn", false, Point(1, col));
        //ChessPiece* piece = static_cast<ChessPiece*>(pawn);  // Explicit conversion
        setPiece(std::make_unique<Pawn>("WP", true, Point(6, col)));
    }

    // Create black king

    // Create black queen

    // Create black knight

    // Create black bishop

    // Create black rook
    return true;
}

// Return the pointer to the piece object stored at the location
ChessPiece* Board::getPiece(Point position) const {
    int x = position.x;
    int y = position.y;

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

void Board::printBoard() const {
    Point pt(1,1);

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            ChessPiece* cp = board[row][col].get();

            if (cp) {
                pt = cp->getPosition();
                std::cout << cp->getName() << ',' << (cp->getIsWhite() ? "White" : "Black")
                                    << ',' << '[' << pt.x << ',' << pt.y << ']' << " ";
            } else {
                std::cout << "Empty";
            }
        }
        std::cout << std::endl;
    }
}

void Board::clearBoard()
{

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
                board[row][col].reset();
        }
    }

}