#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
};



// Function to compute coordinates vertically up of a given point
vector<Point> compute_coordinates_up(int x, int y, int max_n) {
    vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(y+n <= 8) 
        {
            int new_x = x;
            int new_y = y + n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}

// Function to compute coordinates vertically down of a given point
vector<Point> compute_coordinates_down(int x, int y, int max_n) {
    vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(y-n > 0 ) 
        {
            int new_x = x;
            int new_y = y - n;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}


// Function to compute coordinates horiz left of a given point
vector<Point> compute_coordinates_left(int x, int y, int max_n) {
    vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(x-n > 0 ) 
        {
            int new_x = x-n;
            int new_y = y;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}

// Function to compute coordinates horiz right of a given point
vector<Point> compute_coordinates_right(int x, int y, int max_n) {
    vector<Point> coordinates;

    // Iterate over possible values of 'n'
    for (int n = 1; n <= max_n; ++n) {
        // Check if the point (x+n, y+n) is within the board
        if(x+n <=8 ) 
        {
            int new_x = x+n;
            int new_y = y;
            coordinates.push_back({new_x, new_y});
        }
    }

    return coordinates;
}








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


vector<Point> compute_knights_moves(int x, int y, int max_n) {
    vector<Point> coordinates;

    int new_x=0;
    int new_y=0;

    new_x = x+1, new_y=y+2;
    if(new_x<=8 && new_y<=8)
    {
        coordinates.push_back({new_x,new_y});
    }

  
    new_x = x+2, new_y=y+1;
    if(new_x<=8 && new_y<=8)
    {
        coordinates.push_back({new_x,new_y});
    }



    new_x= x+2, new_y=y-1;
    if(new_x<=8 && new_y>=1)
    {
        coordinates.push_back({new_x,new_y});
    }    
    new_x=x+1, new_y=y-2;
    if(new_x<=8 && new_y>=1)
    {
        coordinates.push_back({new_x,new_y});
    }    
    new_x=x-2, new_y=y-1;
    if(new_x>=1 && new_y>=1)
    {
        coordinates.push_back({new_x,new_y});
    }    
    new_x=x-1, new_y=y-2;
    if(new_x>=1 && new_y>=1)
    {
        coordinates.push_back({new_x,new_y});
    }    
    new_x=x-2, new_y=y+1;
    if(new_x>=1 && new_y<=8)
    {
        coordinates.push_back({new_x,new_y});
    }    
    new_x=x-1, new_y=y+2;
    if(new_x>=1 && new_y<=8)
    {
        coordinates.push_back({new_x,new_y});
    }


    return coordinates;
}



int main() {
    int x = 8;
    int y = 8;
    int max_n = 8; 
    
    cout << "Initial position: (" << x << ", " << y << ")" << endl;

   
    // Compute possible coordinates vertically up
    vector<Point> possible_coordinates_knight = compute_knights_moves(x, y, max_n);
    cout << "Possible possible_coordinates_up: ";
    for (const auto& point : possible_coordinates_knight) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;

#if 0
    // Compute possible coordinates vertically up
    vector<Point> possible_coordinates_up = compute_coordinates_up(x, y, max_n);
    cout << "Possible possible_coordinates_up: ";
    for (const auto& point : possible_coordinates_up) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;

    // Compute possible coordinates vertically down
    vector<Point> possible_coordinates_down = compute_coordinates_down(x, y, max_n);
    cout << "Possible possible_coordinates_vert_down: ";
    for (const auto& point : possible_coordinates_down) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;

    // Compute possible coordinates horiz left
    vector<Point> possible_coordinates_left = compute_coordinates_left(x, y, max_n);
    cout << "Possible possible_coordinates_horiz_left: ";
    for (const auto& point : possible_coordinates_left) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;

    // Compute possible coordinates horiz right
    vector<Point> possible_coordinates_right = compute_coordinates_right(x, y, max_n);
    cout << "Possible possible_coordinates_horiz_right: ";
    for (const auto& point : possible_coordinates_right) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }
    cout << endl;

   
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
    
#endif
    return 0;
}