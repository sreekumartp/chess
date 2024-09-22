#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>

#include "common.h"

class ChessPiece {
protected:
    std::string name;
    bool isWhite;
    Point position;
    // make the constructor protected so that the class cannot be instantiated directly
    ChessPiece(std::string name, bool isWhite, Point initialPosition);
public:
   
    virtual ~ChessPiece();
    std::string getName() const;
    bool getIsWhite() const;
    Point getPosition() const;
    void setPosition(Point newPosition);
 
};

#endif // CHESSPIECE_H
