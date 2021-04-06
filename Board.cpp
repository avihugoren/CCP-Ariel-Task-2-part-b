#include "Board.hpp"
#include <iostream>
#include <stdexcept>
const unsigned int UNIT_MAX = 4294967295;
using namespace std;
namespace ariel{
    Board::Board()
    {
        col_upper_bound = 0;
        row_upper_bound = 0;
        col_lower_bound = UNIT_MAX;
        row_lower_bound = UNIT_MAX;
    }
    Board:: ~Board()
    {
        
    }
    void Board::post(unsigned int row, unsigned int column, Direction direction, const string &message)
    {
        //Checks if the message is empty
        if(message.empty())
        {
            return;
        }

        //lower bounds checks 
        if(row<row_lower_bound)
        {
           row_lower_bound = row;
        }
        if (column < col_lower_bound)
        {
            col_lower_bound = column;
        }

        //upper bounds checks
        unsigned temp_max_col = column;
        unsigned temp_max_row = row;
    
        //if its Horizontal need to add the length of the message to temp max col
        if (direction == Direction::Horizontal)
        {
            temp_max_col=column + message.length()-1;
        }
        //if its Vertical need to add the length of the message to temp max row
        if(direction == Direction::Vertical)
        {
           temp_max_row =row + message.length()-1;
        }
        //check if the temps are bigger so update the upper bounds 
        if(temp_max_col > col_upper_bound)
        {
           col_upper_bound = temp_max_col;
        }
        if(temp_max_row > row_upper_bound)
        {
           row_upper_bound = temp_max_row;
        }
       
        if (direction == Direction::Horizontal)
        {
            for (unsigned int i = 0 ; i < message.length() ; i++)
            {
                    my_board[row][column+i] = message[i];
            }
        }
        if(direction == Direction::Vertical)
        {
             for (unsigned int i = 0 ; i < message.length() ; i++)
             {
                my_board[row+i][column] = message[i];
             }

        }
    }
    std::string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        string ans;
        if (direction == Direction::Horizontal)
        {
            for (unsigned int i = 0 ; i < length ; i++)
            {
                 if(my_board[row][column+i] != 0)//means that there is something that mapped to this value 
                 {
                    ans+= my_board[row][column+i];
                 }
                 else // nothing mapped so add '_'
                 {
                      ans += '_';
                 }
            }   
        }   
        if(direction == Direction::Vertical)
        {
             for (unsigned int i = 0 ; i < length ; i++)
             {
                 if(my_board[row+i][column] != 0)
                 {
                    ans+= my_board[row+i][column];
                 }
                 else
                 {
                    ans += '_';
                 }
             }
        }
        return ans;
    }
    void Board::show()
    {
        for (unsigned int row = row_lower_bound ; row <= row_upper_bound ; row++)
        {
            for (unsigned int col = col_lower_bound ; col <= col_upper_bound ; col++)
            {
                if(my_board[row][col] != 0) 
                 {
                    cout <<  my_board[row][col];
                 }
                else
                {
                    cout << '_';
                }
                    
            }
            cout << "\n";
        }
    }
}


