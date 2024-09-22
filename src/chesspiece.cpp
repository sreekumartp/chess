#include "../include/chesspiece.h"


//ChessPiece class implementation

ChessPiece::ChessPiece(std::string name, bool isWhite, Point initialPosition) : name(name), isWhite(isWhite), position(initialPosition) 
{}

ChessPiece::~ChessPiece()
{}

std::string ChessPiece::getName() const
{
    return name;
}

bool ChessPiece::getIsWhite() const
{
    return isWhite;
}

Point ChessPiece::getPosition() const
{
    return position;

}

void ChessPiece::setPosition(Point newPosition)
{

    position = newPosition;
}

