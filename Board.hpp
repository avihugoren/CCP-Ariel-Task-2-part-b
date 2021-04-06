#include <string>
#include "Direction.hpp"
#include <unordered_map>
namespace ariel
{
    class Board{
        std::unordered_map<unsigned int,std::unordered_map<unsigned int,char>> my_board;
        unsigned int col_upper_bound;//the max col that have been written
        unsigned int row_upper_bound;//the max row that have been written
        unsigned int row_lower_bound;//the first row that have been written
        unsigned int col_lower_bound;//the first col that have been written
    public:
        Board();
        
        ~Board();

        void post(unsigned int row,unsigned int column,Direction direction,const std::string &message);

        std::string read(unsigned int row,unsigned int column,Direction direction, unsigned int length);

        void show();
    };
    
}
