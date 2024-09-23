#include "knight.h"


// call ChessPiece constructor to initialize the variables.
Knight::Knight(std::string name , bool isWhite, Point initialPosition) 
    : ChessPiece(name,isWhite,initialPosition){}

Knight::~Knight()
{}

std::string Knight::getName() const
{

return name;

}

Point Knight::getPosition() const
{

return position;

}

bool Knight::getIsWhite() const
{

    return isWhite;
}

void Knight::setPosition(Point newPosition)
{

position = newPosition;

}
