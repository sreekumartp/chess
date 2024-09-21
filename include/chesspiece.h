#ifndef CHESSPIECE_H
#define CHESSPIECE_H

// Your code goes here

#include <string>
#include <vector>
#include <array>

// Structure to represent a point
struct Point {
    int x, y;
    // Define the equality operator
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    };
};

class ChessPiece{

    private:

        std::string name;
        bool isWhite;
        Point position;  

    public:
            ChessPiece(std::string name, bool isWhite, Point initialPosition) : name(name), isWhite(isWhite),
             position(initialPosition) {}
            std::string getName(){return name;};
            bool getIsWhite(){return isWhite;};
            Point getPoint(){return Point();};

            // Add a setter for the position
            void setPosition(Point newPosition) { position = newPosition; }

            virtual std::vector<Point> getLegalMoves(const std::array<std::array<ChessPiece*, 8>, 8>& board) const = 0; 

    

};


#endif // CHESSPIECE_H