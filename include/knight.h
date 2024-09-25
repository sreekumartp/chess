#ifndef KNIGHT_H
#define KNIGHT_H

// #include "../include/chesspiece.h"
// Your code here

#include <string>
#include "common.h"
#include "chesspiece.h"


class Knight : public ChessPiece
{
 

public:

    Knight(std::string name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~Knight();

    Point getPosition() const;
    bool getIsWhite() const;

    void setPosition(Point newPosition);

};



#endif // KNIGHT_H