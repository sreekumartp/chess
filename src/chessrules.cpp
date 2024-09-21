#include <vector>
#include "chessrules.h"



// Function to compute coordinates vertically up of a given point
std::vector<Point> compute_coordinates_up(int x, int y, int max_n) {
    std::vector<Point> coordinates;

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
std::vector<Point> compute_coordinates_down(int x, int y, int max_n) {
    std::vector<Point> coordinates;

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
std::vector<Point> compute_coordinates_left(int x, int y, int max_n) {
    std::vector<Point> coordinates;

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
std::vector<Point> compute_coordinates_right(int x, int y, int max_n) {
    std::vector<Point> coordinates;

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
std::vector<Point> compute_coordinates_left_up(int x, int y, int max_n) {
    std::vector<Point> coordinates;

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
std::vector<Point> compute_coordinates_left_down(int x, int y, int max_n) {
    std::vector<Point> coordinates;

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
std::vector<Point> compute_coordinates_right_up(int x, int y, int max_n) {
    std::vector<Point> coordinates;

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
std::vector<Point> compute_coordinates_right_down(int x, int y, int max_n) {
    std::vector<Point> coordinates;

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


std::vector<Point> compute_knights_moves(int x, int y, int max_n) {
    std::vector<Point> coordinates;

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

