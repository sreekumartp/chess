#include <iostream>
#include "chessrules.h"

int main() {
    int x = 5;
    int y = 3;
    int max_n = 8; 
    
    std::cout << "Initial position: (" << x << ", " << y << ")" << std::endl;

   
    // Compute knight moves
    std::vector<Point> possible_coordinates_knight = compute_knights_moves(x, y, max_n);
    std::cout << "Possible knights_moves: ";
    for (const auto& point : possible_coordinates_knight) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;

#if 1
    // Compute possible coordinates vertically up
    std::vector<Point> possible_coordinates_up = compute_coordinates_up(x, y, max_n);
    std::cout << "Possible possible_coordinates_up: ";
    for (const auto& point : possible_coordinates_up) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;

    // Compute possible coordinates vertically down
    std::vector<Point> possible_coordinates_down = compute_coordinates_down(x, y, max_n);
    std::cout << "Possible possible_coordinates_vert_down: ";
    for (const auto& point : possible_coordinates_down) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;

    // Compute possible coordinates horiz left
    std::vector<Point> possible_coordinates_left = compute_coordinates_left(x, y, max_n);
    std::cout << "Possible possible_coordinates_horiz_left: ";
    for (const auto& point : possible_coordinates_left) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;

    // Compute possible coordinates horiz right
    std::vector<Point> possible_coordinates_right = compute_coordinates_right(x, y, max_n);
    std::cout << "Possible possible_coordinates_horiz_right: ";
    for (const auto& point : possible_coordinates_right) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;

   
    // Compute possible coordinates left up
    std::vector<Point> possible_coordinates_left_up = compute_coordinates_left_up(x, y, max_n);
    std::cout << "Possible possible_coordinates_left_up: ";
    for (const auto& point : possible_coordinates_left_up) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;

    //Compute possible coordinates right up
    std::vector<Point> possible_coordinates_right_up = compute_coordinates_right_up(x, y, max_n);
    std::cout << "Possible possible_coordinates_right_up: ";
    for (const auto& point : possible_coordinates_right_up) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;
    


    // Compute possible coordinates left down
    std::vector<Point> possible_coordinates_left_down = compute_coordinates_left_down(x, y, max_n);
    std::cout << "Possible possible_coordinates_left_down: ";
    for (const auto& point : possible_coordinates_left_down) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;


    //Compute possible coordinates right down
    std::vector<Point> possible_coordinates_right_down = compute_coordinates_right_down(x, y, max_n);
    std::cout << "Possible possible_coordinates_right_down: ";
    for (const auto& point : possible_coordinates_right_down) {
        std::cout << "(" << point.x << ", " << point.y << ") ";
    }
    std::cout << std::endl;
    
#endif
    return 0;
}