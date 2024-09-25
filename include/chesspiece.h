#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>

#include "common.h"

class ChessPiece {
protected:
    std::string name;
    bool isWhite;
    Point position;
 
public:
    
    ChessPiece(const std::string& name, bool isWhite, Point initialPosition);
 
    virtual ~ChessPiece();  // Add a virtual destructor

    std::string getName() const;
    bool getIsWhite() const;
    Point getPosition() const;
    void setPosition(Point newPosition);
 
};

#endif // CHESSPIECE_H
