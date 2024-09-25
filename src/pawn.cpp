#include "pawn.h"


// call ChessPiece constructor to initialize the variables.
Pawn::Pawn(const std::string& name , bool isWhite, Point initialPosition) 
    : ChessPiece(name,isWhite,initialPosition){}

Pawn::~Pawn()
{}

std::string Pawn::getName() const
{

return name;

}

Point Pawn::getPosition() const
{

return position;

}

bool Pawn::getIsWhite() const
{

    return isWhite;
}

void Pawn::setPosition(Point newPosition)
{

position = newPosition;

}
