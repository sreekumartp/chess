#include "bishop.hpp"


// call ChessPiece constructor to initialize the variables.
Bishop::Bishop(const std::string& name , bool isWhite, Point initialPosition) 
    : ChessPiece(name,isWhite,initialPosition){}

Bishop::~Bishop()
{}

std::string Bishop::getName() const
{

return name;

}

Point Bishop::getPosition() const
{

return position;

}

void Bishop::setPosition(Point newPosition)
{

position = newPosition;

}
