#ifndef CHESSBOARD_H
#define CHESSBOARD_H

// Your code here
#include <memory>
#include <array>
#include "chesspiece.h"
#include "common.h"


class Board{
    private:
        std::array<std::array<std::unique_ptr<ChessPiece >, 8>, 8> board;
    public:
        Board();
        ~Board();
        ChessPiece* getPiece(Point position) const;
        void setPiece(Point position, std::unique_ptr<ChessPiece> piece);
        void movePiece(Point start, Point end);
        void printBoard() const;
        void clearBoard();
        bool InitialiseBoard();
};

#endif // CHESSBOARD_H