#ifndef KING_H
#define KING_H

// #include "../include/chesspiece.hpp"
// Your code here

#include <string>
#include "chesspiece.hpp"
#include "common.hpp" 


class King:public ChessPiece{


public:

    King(const std::string& name , bool isWhite, Point initialPosition);
    std::string getName() const;

    ~King();

    Point getPosition() const;
    bool getIsWhite() const;
    void setPosition(Point newPosition);

};



#endif // KING_H