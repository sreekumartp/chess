#ifndef KING_H
#define KING_H

// #include "../include/chesspiece.h"
// Your code here

#include <string>
#include "chesspiece.h"
#include "common.h" 


class King:public ChessPiece{


public:

    King(std::string name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~King();

    Point getPosition() const;
    bool getIsWhite() const;
    void setPosition(Point newPosition);

};



#endif // KING_H