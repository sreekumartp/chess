#ifndef CHESSBOARD_H
#define CHESSBOARD_H

// Your code here
#include <array>
#include <iostream>
#include "chesspiece.h"
#include "common.h"

class Board{
    private:
        std::array<std::array<ChessPiece*, 8>, 8> board;
    public:
        Board(){};
        ~Board(){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(board[i][j] != nullptr){
                        delete board[i][j];
                    }
                }
            }
        };
        ChessPiece* getPiece(Point position) const{
            return board[position.x][position.y];
        };
        void setPiece(Point position, ChessPiece* piece){
            board[position.x][position.y] = piece;
        };
        void movePiece(Point start, Point end){
            board[end.x][end.y] = board[start.x][start.y];
            board[start.x][start.y] = nullptr;
        };
        void printBoard() const{
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(board[i][j] == nullptr){
                        std::cout << "0 ";
                    }else{
                        std::cout << board[i][j]->getName() << " ";
                    }
                }
                std::cout << std::endl;
            }
        };
};

#endif // CHESSBOARD_H