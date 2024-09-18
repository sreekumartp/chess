#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
};

// Function to compute coordinates to the left and diagonaly up of a given point
vector<Point> compute_coordinates(int x, int y, int max_n) {
    vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(x-n > 0 && y+n <= 8) 
        {
            int new_x = x - n;
            int new_y = y + n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}

int main() {
    int x = 7;
    int y = 7;
    int max_n = 8; 

    vector<Point> possible_coordinates = compute_coordinates(x, y, max_n);

    cout << "Possible coordinates: ";
    for (const auto& point : possible_coordinates) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;

    return 0;
}