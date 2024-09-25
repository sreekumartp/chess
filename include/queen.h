#ifndef QUEEN_H
#define QUEEN_H

// #include "../include/chesspiece.h"
// Your code here

#include <string>
#include "chesspiece.h"


class Queen:public ChessPiece
{


public:

    Queen(const std::string& name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~Queen();

    Point getPosition() const;

    void setPosition(Point newPosition);

};



#endif // QUEEN_H