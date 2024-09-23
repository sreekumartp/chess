#ifndef ROOK_H
#define ROOK_H

// #include "../include/chesspiece.h"
// Your code here

#include "chesspiece.h"
#include "common.h"

class Rook:ChessPiece{


public:

    Rook(std::string name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~Rook();

    Point getPosition() const;

    void setPosition(Point newPosition);

};



#endif // ROOK_H