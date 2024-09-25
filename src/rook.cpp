#include "rook.h"


// call ChessPiece constructor to initialize the variables.
Rook::Rook(const std::string& name , bool isWhite, Point initialPosition) 
    : ChessPiece(name,isWhite,initialPosition){}

Rook::~Rook()
{}

std::string Rook::getName() const
{

return name;

}

Point Rook::getPosition() const
{

return position;

}

void Rook::setPosition(Point newPosition)
{

position = newPosition;

}
