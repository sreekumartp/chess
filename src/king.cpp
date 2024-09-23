#include "king.h"


// call ChessPiece constructor to initialize the variables.
King::King(std::string name , bool isWhite, Point initialPosition) 
    : ChessPiece(name,isWhite,initialPosition){}

King::~King()
{}

std::string King::getName() const
{

return name;

}

Point King::getPosition() const
{

return position;

}

bool King::getIsWhite() const
{

    return isWhite;
}


void King::setPosition(Point newPosition)
{

position = newPosition;

}
