#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
};


// Function to compute coordinates to the right and diagonaly up of a given point
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

// Function to compute coordinates to the left and diagonaly up of a given point
vector<Point> compute_coordinates_right_up(int x, int y, int max_n) {
    vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(x+n <= 8 && y+n <= 8) 
        {
            int new_x = x + n;
            int new_y = y + n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}

int main() {
    int x = 7;
    int y = 2;
    int max_n = 8; 
    
    // Compute possible coordinates left up
    vector<Point> possible_coordinates_left_up = compute_coordinates(x, y, max_n);
    cout << "Possible possible_coordinates_left_up: ";
    for (const auto& point : possible_coordinates_left_up) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;

    //Compute possible coordinates right up
    vector<Point> possible_coordinates_right_up = compute_coordinates_right_up(x, y, max_n);
    cout << "Possible possible_coordinates_right_up: ";
    for (const auto& point : possible_coordinates_right_up) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;

    return 0;
}