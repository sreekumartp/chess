#ifndef PAWN_H
#define PAWN_H

// #include "../include/chesspiece.h"
// Your code here

#include <string>
#include "chesspiece.h"
#include "common.h"

class Pawn:public ChessPiece{


public:

    Pawn(std::string name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~Pawn();

    Point getPosition() const;
    bool getIsWhite() const;
    void setPosition(Point newPosition);

};



#endif // PAWN_H