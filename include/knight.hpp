#ifndef KNIGHT_H
#define KNIGHT_H

// #include "../include/chesspiece.hpp"
// Your code here

#include <string>
#include "common.hpp"
#include "chesspiece.hpp"


class Knight : public ChessPiece
{
 

public:

    Knight(const std::string& name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~Knight();

    Point getPosition() const;
    bool getIsWhite() const;

    void setPosition(Point newPosition);

};



#endif // KNIGHT_H