#ifndef COMMON_H
#define COMMON_H

// Your code here
// Structure to represent a point
struct Point {
    int x=-1, y=-1;
      // Default constructor
    Point() : x(-1), y(-1) {}
    Point(int x, int y) : x(x), y(y) {};
    // Define the equality operator
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

};

#endif // COMMON_H