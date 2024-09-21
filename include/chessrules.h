#ifndef CHESSRULES_H
#define CHESSRULES_H

#include <vector>

// Structure to represent a point
struct Point {
    int x, y;
    // Define the equality operator
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

};

// Function to compute coordinates vertically up of a given point
std::vector<Point> compute_coordinates_up(int x, int y, int max_n);
// Function to compute coordinates vertically down of a given point
std::vector<Point> compute_coordinates_down(int x, int y, int max_n);
// Function to compute coordinates horiz left of a given point
std::vector<Point> compute_coordinates_left(int x, int y, int max_n);
// Function to compute coordinates horiz right of a given point
std::vector<Point> compute_coordinates_right(int x, int y, int max_n);
// Function to compute coordinates to the right and diagonaly up of a given point
std::vector<Point> compute_coordinates_left_up(int x, int y, int max_n); 
// Function to compute coordinates to the right and diagonaly up of a given point
std::vector<Point> compute_coordinates_left_down(int x, int y, int max_n);
// Function to compute coordinates to the left and diagonaly up of a given point
std::vector<Point> compute_coordinates_right_up(int x, int y, int max_n);
// Function to compute coordinates to the right and diagonally down of a given point
std::vector<Point> compute_coordinates_right_down(int x, int y, int max_n);
// Function to compute the possible moves of a knight
std::vector<Point> compute_knights_moves(int x, int y, int max_n);

#endif // CHESSRULES_H