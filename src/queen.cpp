#include "queen.h"


// call ChessPiece constructor to initialize the variables.
Queen::Queen(std::string name , bool isWhite, Point initialPosition) 
    : ChessPiece(name,isWhite,initialPosition){}

Queen::~Queen()
{}

std::string Queen::getName() const
{

return name;

}

Point Queen::getPosition() const
{

return position;

}

void Queen::setPosition(Point newPosition)
{

position = newPosition;

}
