#ifndef QUEEN_H
#define QUEEN_H

// #include "../include/chesspiece.h"
// Your code here

#include "chesspiece.h"
#include "common.h"

class Queen:ChessPiece{


public:

    Queen(std::string name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~Queen();

    Point getPosition() const;

    void setPosition(Point newPosition);

};



#endif // QUEEN_H