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
    // Define the less-than operator for sorting
    bool operator<(const Point& other) const {
      if (x == other.x) {
        return y < other.y;
      }
      return x < other.x;
    }

};


inline bool isWithinBoard(int x, int y) {
  return 0 <= x && x <= 7 && 0 <= y && y <= 7;
}

inline bool isNotOnEdge(int x, int y) {
  return 1 <= x && x <= 6 && 1 <= y && y <= 6;
}

#include <map>
#include <string>

inline std::map<std::string, Point> initializeStartingPositions() {
  std::map<std::string, Point> startingPositions;
  startingPositions["WR1"] = Point(0, 0);
  startingPositions["WN1"] = Point(1, 0);
  startingPositions["WB1"] = Point(2, 0);
  startingPositions["WQ"] = Point(3, 0);
  startingPositions["WK"] = Point(4, 0);
  startingPositions["WB2"] = Point(5, 0);
  startingPositions["WN2"] = Point(6, 0);
  startingPositions["WR2"] = Point(7, 0);
  for (int i = 0; i < 8; ++i) {
    startingPositions["WP_" + std::to_string(i + 1)] = Point(i, 1);
  }

  startingPositions["BR1"] = Point(0, 7);
  startingPositions["BN1"] = Point(1, 7);
  startingPositions["BP1"] = Point(2, 7);
  startingPositions["BQ"] = Point(3, 7);
  startingPositions["BK"] = Point(4, 7);
  startingPositions["BP2"] = Point(5, 7);
  startingPositions["BN2"] = Point(6, 7);
  startingPositions["BR2"] = Point(7, 7);
  for (int i = 0; i < 8; ++i) {
    startingPositions["BP_" + std::to_string(i + 1)] = Point(i, 6);
  }

  return startingPositions;
}

#endif // COMMON_H