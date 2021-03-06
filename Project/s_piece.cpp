// PHYS 30762 Programming in C++
// Final Project
// Clea Dronne - 29/04/2022

// Initializes S Piece class - derived class of Tetrominos
// 2 rotation states

#include <iostream>
#include <string>
#include "board.h"
#include "s_piece.h"

// Constructor
s_piece::s_piece(board & board) 
{
    piece = new std::string[4];

    for (int i{};i<4;i++){
        piece[i]="#";
    }

    vertical_position = 1; 
    horizontal_position = board.get_length()/2-1; 

}

// Destructor
s_piece::~s_piece()
{
    std::cout << "delete piece" << std::endl;
    horizontal_position=0;
    vertical_position=0;
    rotation=0;
    delete[] piece;
}

// Prints piece by modiying board
void s_piece::print_piece(board & board) 
{
    std::string* game_console = board.get_console();
    int height {board.get_height()};
    int length {board.get_length()};

    switch (rotation)
    {
        case 0: 
            game_console[board.index(horizontal_position+1,vertical_position)]=piece[0];
            game_console[board.index(horizontal_position+2,vertical_position)]=piece[1];
            game_console[board.index(horizontal_position,vertical_position+1)]=piece[2];
            game_console[board.index(horizontal_position+1,vertical_position+1)]=piece[3];
            break;
         
        case 1:  
            game_console[board.index(horizontal_position,vertical_position)]=piece[0];
            game_console[board.index(horizontal_position,vertical_position+1)]=piece[1];
            game_console[board.index(horizontal_position+1,vertical_position+1)]=piece[2];
            game_console[board.index(horizontal_position+1,vertical_position+2)]=piece[3];
            break;
    }
}

// Piece moves down one line
void s_piece::move_down(board & board) 
{
    std::string* game_console = board.get_console();
    int height {board.get_height()};
    int length {board.get_length()};

    switch (rotation)
    {
        case 0:
            game_console[board.index(horizontal_position+1,vertical_position)]=" ";
            game_console[board.index(horizontal_position+2,vertical_position)]=" ";
            game_console[board.index(horizontal_position,vertical_position+1)]=" ";
            game_console[board.index(horizontal_position+1,vertical_position+1)]=" ";

            vertical_position+=1;

            game_console[board.index(horizontal_position+1,vertical_position)]=piece[0];
            game_console[board.index(horizontal_position+2,vertical_position)]=piece[1];
            game_console[board.index(horizontal_position,vertical_position+1)]=piece[2];
            game_console[board.index(horizontal_position+1,vertical_position+1)]=piece[3];
            break;
        case 1:
            game_console[board.index(horizontal_position,vertical_position)]=" ";
            game_console[board.index(horizontal_position,vertical_position+1)]=" ";
            game_console[board.index(horizontal_position+1,vertical_position+1)]=" ";
            game_console[board.index(horizontal_position+1,vertical_position+2)]=" ";

            vertical_position+=1;

            game_console[board.index(horizontal_position,vertical_position)]=piece[0];
            game_console[board.index(horizontal_position,vertical_position+1)]=piece[1];
            game_console[board.index(horizontal_position+1,vertical_position+1)]=piece[2];
            game_console[board.index(horizontal_position+1,vertical_position+2)]=piece[3];
            break;  
    }  
}

// Piece moves right one column
void s_piece::move_right(board &board)
{
    std::string* game_console = board.get_console();
    int height {board.get_height()};
    int length {board.get_length()};


    if (!right_wall(board)) {
        switch (rotation)
        {
            case 0:
                game_console[board.index(horizontal_position+1,vertical_position)]=" ";
                game_console[board.index(horizontal_position+2,vertical_position)]=" ";
                game_console[board.index(horizontal_position,vertical_position+1)]=" ";
                game_console[board.index(horizontal_position+1,vertical_position+1)]=" ";

                horizontal_position+=1;

                game_console[board.index(horizontal_position+1,vertical_position)]=piece[0];
                game_console[board.index(horizontal_position+2,vertical_position)]=piece[1];
                game_console[board.index(horizontal_position,vertical_position+1)]=piece[2];
                game_console[board.index(horizontal_position+1,vertical_position+1)]=piece[3];
                break;
            case 1:
                game_console[board.index(horizontal_position,vertical_position)]=" ";
                game_console[board.index(horizontal_position,vertical_position+1)]=" ";
                game_console[board.index(horizontal_position+1,vertical_position+1)]=" ";
                game_console[board.index(horizontal_position+1,vertical_position+2)]=" ";

                horizontal_position+=1;

                game_console[board.index(horizontal_position,vertical_position)]=piece[0];
                game_console[board.index(horizontal_position,vertical_position+1)]=piece[1];
                game_console[board.index(horizontal_position+1,vertical_position+1)]=piece[2];
                game_console[board.index(horizontal_position+1,vertical_position+2)]=piece[3];
                break;  
        }  
    }   
}

// Piece moves left one column
void s_piece::move_left(board &board)
{
    std::string* game_console = board.get_console();
    int height {board.get_height()};
    int length {board.get_length()};


    if (!left_wall(board)) {
        switch (rotation)
        {

            case 0:
                game_console[board.index(horizontal_position+1,vertical_position)]=" ";
                game_console[board.index(horizontal_position+2,vertical_position)]=" ";
                game_console[board.index(horizontal_position,vertical_position+1)]=" ";
                game_console[board.index(horizontal_position+1,vertical_position+1)]=" ";

                horizontal_position-=1;

                game_console[board.index(horizontal_position+1,vertical_position)]=piece[0];
                game_console[board.index(horizontal_position+2,vertical_position)]=piece[1];
                game_console[board.index(horizontal_position,vertical_position+1)]=piece[2];
                game_console[board.index(horizontal_position+1,vertical_position+1)]=piece[3];
                break;
            case 1:
                game_console[board.index(horizontal_position,vertical_position)]=" ";
                game_console[board.index(horizontal_position,vertical_position+1)]=" ";
                game_console[board.index(horizontal_position+1,vertical_position+1)]=" ";
                game_console[board.index(horizontal_position+1,vertical_position+2)]=" ";

                horizontal_position-=1;

                game_console[board.index(horizontal_position,vertical_position)]=piece[0];
                game_console[board.index(horizontal_position,vertical_position+1)]=piece[1];
                game_console[board.index(horizontal_position+1,vertical_position+1)]=piece[2];
                game_console[board.index(horizontal_position+1,vertical_position+2)]=piece[3];
                break;  
        }  
    }        
}

// Piece rotates clockwise
void s_piece::rotate(board &board)
{
    std::string* game_console = board.get_console();
    int height {board.get_height()};
    int length {board.get_length()};

    switch (rotation)
    {
        case 0:
            if (vertical_position<height) { 
                try {
                    if (game_console[board.index(horizontal_position+2,vertical_position+2)]==" ") {
                                
                        game_console[board.index(horizontal_position+1,vertical_position)]=" ";
                        game_console[board.index(horizontal_position+2,vertical_position)]=" ";
                        game_console[board.index(horizontal_position,vertical_position+1)]=" ";
                        game_console[board.index(horizontal_position+1,vertical_position+1)]=" ";
            
                        horizontal_position+=1;

                        game_console[board.index(horizontal_position,vertical_position)]=piece[0];
                        game_console[board.index(horizontal_position,vertical_position+1)]=piece[1];
                        game_console[board.index(horizontal_position+1,vertical_position+1)]=piece[2];
                        game_console[board.index(horizontal_position+1,vertical_position+2)]=piece[3];
                        rotation=1; 
                    }
                } catch (std::out_of_range& except) {}
            }
            break;

        case 1:
            if (horizontal_position>1) {
                try {
                    if (game_console[board.index(horizontal_position-1,vertical_position+2)]==" ") {
            
                        game_console[board.index(horizontal_position,vertical_position)]=" ";
                        game_console[board.index(horizontal_position,vertical_position+1)]=" ";
                        game_console[board.index(horizontal_position+1,vertical_position+1)]=" ";
                        game_console[board.index(horizontal_position+1,vertical_position+2)]=" ";

                        horizontal_position-=1;
                        vertical_position+=1;
                        
                        game_console[board.index(horizontal_position+1,vertical_position)]=piece[0];
                        game_console[board.index(horizontal_position+2,vertical_position)]=piece[1];
                        game_console[board.index(horizontal_position,vertical_position+1)]=piece[2];
                        game_console[board.index(horizontal_position+1,vertical_position+1)]=piece[3];

                        rotation=0;
                    }
                } catch (std::out_of_range& except) {}
            }
            break;

        default:
            break;
    }
}

// Piece blocked and can't move down
bool s_piece::bottom_wall(board &board)
{
    std::string* game_console = board.get_console();
    int height {board.get_height()};
    int length {board.get_length()};

    switch (rotation) 
    {
        case 0:
            if (vertical_position==height-1) {
                return true;
            } else if (game_console[board.index(horizontal_position,vertical_position+2)] =="#") {
                return true;
            } else if (game_console[board.index(horizontal_position+1,vertical_position+2)] =="#") {
                return true;
            } else if (game_console[board.index(horizontal_position+2,vertical_position+1)] =="#") {
                return true;
            } else {
                return false;
            }
            break;
    
        case 1:
            if (vertical_position==height-2) {
                return true;
            } else if (game_console[board.index(horizontal_position,vertical_position+2)] =="#") {
                return true;
            } else if (game_console[board.index(horizontal_position+1,vertical_position+3)] =="#") {
                return true;
            } else {
                return false;
            }
            break;
        
        default:
            return false;
            break;
    }
}

// Piece blocked and can't move right
bool s_piece::right_wall(board &board)
{
    std::string* game_console = board.get_console();
    int height {board.get_height()};
    int length {board.get_length()};

    switch (rotation) 
    {
        case 0:
            if (horizontal_position+2==length) {
                return true;
            } else if (game_console[board.index(horizontal_position+3,vertical_position)]=="#") {
                return true;
            } else if (game_console[board.index(horizontal_position+2,vertical_position+1)]=="#") {
                return true;
            } else {
                return false;
            }
            break;
        case 1: 
            if (horizontal_position+1==length) {
                return true;
            } else if (game_console[board.index(horizontal_position+1,vertical_position)]=="#") {
                return true;
            } else if (game_console[board.index(horizontal_position+2,vertical_position+1)]=="#") {
                return true;
            } else if (game_console[board.index(horizontal_position+2,vertical_position+2)]=="#") {
                return true;
            } else {
                return false;
            }
            break;
        default:
            return false;
            break;
    }  
}

// Piece blocked and can't move left
bool s_piece::left_wall(board &board)
{
    std::string* game_console = board.get_console();
    int height {board.get_height()};
    int length {board.get_length()};

    switch(rotation)
    {
        case 0: 
            if (horizontal_position==1) {
                return true; 
            } else if (game_console[board.index(horizontal_position,vertical_position)]=="#") {
                return true;
            } else if (game_console[board.index(horizontal_position-1,vertical_position+1)]=="#") {
                return true;
            } else {
                return false;
            }
            break;
        case 1:
            if (horizontal_position==1) {
                return true;
            } else if (game_console[board.index(horizontal_position-1,vertical_position)]=="#") {
                return true;
            } else if (game_console[board.index(horizontal_position-1,vertical_position+1)]=="#") {
                return true;
            } else if (game_console[board.index(horizontal_position,vertical_position+2)]=="#") {
                return true;
            } else {
                return false;
            }
            break;

        default:
            return false;
            break;
    }
}