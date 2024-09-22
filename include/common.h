#ifndef COMMON_H
#define COMMON_H

// Your code here
// Structure to represent a point
struct Point {
    int x, y;
    // Define the equality operator
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

};

#endif // COMMON_H