#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <unordered_map>
#include <windows.h> 
#define SIZE 8

using namespace std;


class Chess {
private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool is_ek = 0;
	vector<vector<int>> steps;
	set<vector<int>> hits;
	unordered_map<char, string> symoles_unicode = { {' ', " "},{'.', "."},
		{'K', "♔"},{'Q', "♕"},{'R', "♖"}, {'B', "♗"}, {'N', "♘"}, {'P', "♙"},
		{ 'k',"♚" }, {'q',"♛"}, { 'r', "♜" }, {'b',"♝"}, {'n', "♞"}, {'p', "♟"} };
	char board[SIZE][SIZE]{
		//    a	  b   c   d   e   f   g   h 
			{'R','N','B','Q','K','B','N','R'},// 8

			{'P','P','P','P','P','P','P','P'},// 7

			{' ',' ',' ',' ',' ',' ',' ',' '},// 6

			{' ',' ',' ',' ',' ',' ',' ',' '},// 5

			{' ',' ',' ',' ',' ',' ',' ',' '},// 4

			{' ',' ',' ',' ',' ',' ',' ',' '},// 3

			{'p','p','p','p','p','p','p','p'},// 2

			{'r','n','b','q','k','b','n','r'} // 1
	};
	int f_x = 0;
	int f_y = 0;
	unordered_map<char, int> x_map{ {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}, };

	bool is_Check(char color, char board[SIZE][SIZE]);
public:
	char end_fl = ' ';
	bool step_from(string from);
	bool step_to(string to);
	void print_boar();
	
};