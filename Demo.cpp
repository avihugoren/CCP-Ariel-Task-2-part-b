/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	ariel::Board board;
	board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
	cout << board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) << endl;  
		// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "xyz");
	cout << board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6) << endl;  
		// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

	board.show(); // shows the board in a reasonable way. For example:
	ariel::Board board_over_ride;
	cout<<'\n';
	board_over_ride.post(10000,10000,Direction::Horizontal,"Lets see Horizontal override");
	board_over_ride.post(10001,10000,Direction::Horizontal,"Lets see Horizontal override");
	board_over_ride.post(10002,10000,Direction::Horizontal,"Lets see Horizontal override");
	board_over_ride.post(10003,10000,Direction::Horizontal,"Lets see Horizontal override");
	board_over_ride.show();
	cout<<'\n';
	board_over_ride.post(10000,10000,Direction::Horizontal,"override override override override");
	board_over_ride.post(10001,10000,Direction::Horizontal,"override override override override");
	board_over_ride.post(10002,10000,Direction::Horizontal,"override override override override");
	board_over_ride.post(10003,10000,Direction::Horizontal,"override override override override");
	board_over_ride.show();
	cout<<'\n';
	ariel::Board board_over_ride_vertical;
	board_over_ride_vertical.post(10000,10001,Direction::Vertical,"Lets see Vertical override");
	board_over_ride_vertical.post(10000,10002,Direction::Vertical,"Lets see Vertical override");
	board_over_ride_vertical.post(10000,10003,Direction::Vertical,"Lets see Vertical override");
	board_over_ride_vertical.post(10000,10004,Direction::Vertical,"Lets see Vertical override");
	board_over_ride_vertical.show();
	cout<<'\n';
	board_over_ride_vertical.post(10000,10001,Direction::Vertical,"override override override override");
	board_over_ride_vertical.post(10000,10002,Direction::Vertical,"override override override override");
	board_over_ride_vertical.post(10000,10003,Direction::Vertical,"override override override override");
	board_over_ride_vertical.post(10000,10004,Direction::Vertical,"override override override override");
	cout<<'\n';
	board_over_ride_vertical.show();
	cout<<'\n';
	cout<<"big number post x=4294967000,y=4294967000"<<endl;
	ariel::Board board_big_num;
	board_big_num.post(4294967000,4294967000,Direction::Horizontal,"Big Number");
	board_big_num.post(4294967001,4294967000,Direction::Horizontal,"Big Number");
	board_big_num.post(4294967002,4294967000,Direction::Horizontal,"Big Number");
	board_big_num.post(4294967003,4294967000,Direction::Horizontal,"Big Number");
	board_big_num.post(4294967004,4294967000,Direction::Horizontal,"Big Number");
	board_big_num.show();
	cout<<'\n';
	cout<<"adds big index vertical post"<<endl;
	board_big_num.post(4294967000,4294967011,Direction::Vertical,"Big Number");
	cout<<'\n';
	board_big_num.show();
	ariel::Board board_end;
	board_end.post(100,101,Direction::Horizontal,"===============================================");
    board_end.post(124,100,Direction::Horizontal,"================================================");

	board_end.post(100,147,Direction::Vertical,"|||||||||||||||||||||||||");
	board_end.post(100,100,Direction::Vertical,"|||||||||||||||||||||||||");
	//T
	board_end.post(103,102,Direction::Horizontal,"+++++++++++++++");
	board_end.post(104,109,Direction::Vertical,"++++++");
	//H
	board_end.post(103,119,Direction::Vertical,"+++++++");
	board_end.post(103,127,Direction::Vertical,"+++++++");
	board_end.post(106,120,Direction::Horizontal,"+++++++");
	//E
	board_end.post(103,131,Direction::Vertical,"+++++++");
	board_end.post(103,132,Direction::Horizontal,"+++++++");
	board_end.post(106,132,Direction::Horizontal,"+++++++");
	board_end.post(109,132,Direction::Horizontal,"+++++++");
	//E
	board_end.post(112,105,Direction::Vertical,"+++++++");
	board_end.post(112,106,Direction::Horizontal,"+++++++");
	board_end.post(115,106,Direction::Horizontal,"+++++++");
	board_end.post(118,106,Direction::Horizontal,"+++++++");
	//N
	board_end.post(112,116,Direction::Vertical,"+++++++");
	board_end.post(112,124,Direction::Vertical,"+++++++");
	for (unsigned int i = 112, j=117;i<119;i+=1,j+=1)
	{
	  board_end.post(i,j,Direction::Horizontal,"+");
	}
	board_end.post(112,117,Direction::Horizontal,"+");
	//D
	board_end.post(112,128,Direction::Vertical,"+++++++");
	board_end.post(112,129,Direction::Horizontal,"++++");
	board_end.post(118,129,Direction::Horizontal,"++++");
	board_end.post(113,133,Direction::Horizontal,"+");
	board_end.post(114,134,Direction::Horizontal,"+");
	board_end.post(115,134,Direction::Horizontal,"+");
	board_end.post(116,133,Direction::Horizontal,"+");
	board_end.post(117,132,Direction::Horizontal,"+");
	board_end.show();







}

