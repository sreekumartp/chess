#ifndef ROOK_H
#define ROOK_H

// #include "../include/chesspiece.h"
// Your code here
#include <string>
#include "chesspiece.h"
#include "common.h"

class Rook:public ChessPiece{


public:

    Rook(const std::string& name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~Rook();

    Point getPosition() const;

    void setPosition(Point newPosition);

};



#endif // ROOK_H