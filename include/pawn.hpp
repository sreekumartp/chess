#ifndef PAWN_H
#define PAWN_H

// #include "../include/chesspiece.hpp"
// Your code here

#include <string>
#include "chesspiece.hpp"
#include "common.hpp"

class Pawn:public ChessPiece{


public:

    Pawn(const std::string& name , bool isWhite, Point initialPosition);
    std::string getName() const;

    virtual ~Pawn();

    Point getPosition() const;
    bool getIsWhite() const;
    void setPosition(Point newPosition);

};



#endif // PAWN_H