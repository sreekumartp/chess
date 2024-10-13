#ifndef COMMON_H
#define COMMON_H


#include <map>
#include <string>
#include <vector>
#include <algorithm>

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


class ChessboardMapper {
public:
    ChessboardMapper() {
        initializeMaps();
    }

    Point getCoordinates(const std::string& chessPosition) const {
        return chessToCoordinates.at(chessPosition);
    }

    std::string getChessPosition(const Point& point) const {
        return coordinatesToChess.at(point);
    }
// New method to convert a 2D vector of Points to chess positions
    std::vector<std::vector<std::string>> convertCoordinatesToChessPositions(
        const std::vector<std::vector<Point>>& coordinates) const 
    {
        std::vector<std::vector<std::string>> chessPositions;
        for (const auto& row : coordinates) {
            std::vector<std::string> chessRow(row.size());
            std::transform(row.begin(), row.end(), chessRow.begin(), [this](const Point& point) { return this->getChessPosition(point); });
            chessPositions.push_back(chessRow);
        }
        return chessPositions;
    }

      std::vector<std::string> convertCoordinatesToChessPositions(
        const std::vector<Point>& coordinates) const 
    {
        std::vector<std::string> chessPositions;
  
        std::transform(coordinates.begin(), coordinates.end(),std::back_inserter(chessPositions),[this](const Point &point){return this->getChessPosition(point);});

        return chessPositions;
    }
  

private:
    void initializeMaps() {
        if (chessToCoordinates.empty()) {

            for (int col = 0; col < 8; ++col) {
              for (int row = 0; row < 8; ++row) {
                    std::string chessNotation = std::string(1, 'a' + col) + std::to_string(row+1);
                    chessToCoordinates[chessNotation] = Point(col, row);
                    coordinatesToChess[Point(col, row)] = chessNotation;
                }
            }
        }
    }

    std::map<std::string, Point> chessToCoordinates;
    std::map<Point, std::string> coordinatesToChess;
};




inline bool isWithinBoard(int x, int y) {
  return 0 <= x && x <= 7 && 0 <= y && y <= 7;
}

inline bool isNotOnEdge(int x, int y) {
  return 1 <= x && x <= 6 && 1 <= y && y <= 6;
}

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

 class ExpectedMoves {
    public:
        std::vector<std::string> expected_algebraic ;

      explicit ExpectedMoves(const std::vector<std::string>& ea):expected_algebraic(ea){};

        std::vector<Point> getExpectedPoints(const ChessboardMapper& mapper) const {
            std::vector<Point> expected;
            std::transform(expected_algebraic.begin(), expected_algebraic.end(), std::back_inserter(expected), [&mapper](const std::string& pos) {
                return mapper.getCoordinates(pos);
            });
            return expected;
        }
    };

    
#endif // COMMON_H