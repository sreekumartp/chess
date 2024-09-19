#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
};


// Function to compute coordinates to the right and diagonaly up of a given point
vector<Point> compute_coordinates_left_up(int x, int y, int max_n) {
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


// Function to compute coordinates to the right and diagonaly up of a given point
vector<Point> compute_coordinates_left_down(int x, int y, int max_n) {
    vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(x-n > 0 && y-n > 0 ) 
        {
            int new_x = x - n;
            int new_y = y - n;
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


// Function to compute coordinates to the right and diagonally down of a given point
vector<Point> compute_coordinates_right_down(int x, int y, int max_n) {
    vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        //check if coordinates are withing the boundary and if so store the new coordinate
        if(x+n <= 8 && y-n >0 ) 
        {
            int new_x = x + n;
            int new_y = y - n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}





int main() {
    int x = 4;
    int y = 4;
    int max_n = 8; 
    
    cout << "Initial position: (" << x << ", " << y << ")" << endl;
    
    // Compute possible coordinates left up
    vector<Point> possible_coordinates_left_up = compute_coordinates_left_up(x, y, max_n);
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
    


    // Compute possible coordinates left down
    vector<Point> possible_coordinates_left_down = compute_coordinates_left_down(x, y, max_n);
    cout << "Possible possible_coordinates_left_down: ";
    for (const auto& point : possible_coordinates_left_down) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;


    //Compute possible coordinates right down
    vector<Point> possible_coordinates_right_down = compute_coordinates_right_down(x, y, max_n);
    cout << "Possible possible_coordinates_right_down: ";
    for (const auto& point : possible_coordinates_right_down) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;
    



    return 0;
}