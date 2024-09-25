#ifndef BISHOP_H
#define BISHOP_H

// #include "../include/chesspiece.hpp"
// Your code here

#include "chesspiece.hpp"
#include "common.hpp"

class Bishop:public ChessPiece{


public:

    Bishop(const std::string& name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~Bishop();

    Point getPosition() const;

    void setPosition(Point newPosition);

};



#endif // BISHOP_H