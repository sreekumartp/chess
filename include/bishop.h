#ifndef BISHOP_H
#define BISHOP_H

// #include "../include/chesspiece.h"
// Your code here

#include "chesspiece.h"
#include "common.h"

class Bishop:ChessPiece{


public:

    Bishop(std::string name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~Bishop();

    Point getPosition() const;

    void setPosition(Point newPosition);

};



#endif // BISHOP_H