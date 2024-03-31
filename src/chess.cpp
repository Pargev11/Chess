#include "chess.h"
#include <iostream>

using namespace std;

void steps_P(char board[SIZE][SIZE], int f_x, int f_y, vector<vector<int>>& steps, set<vector<int>>& hits) {
	if (f_y == 1) {
		for (int i = f_y; i < f_y + 3; i++) {
			if (board[i][f_x] == ' ') steps.push_back({ f_x, i });
			else if (i != f_y) break;
		}
	}
	else {
		if (f_y + 1 < SIZE and board[f_y + 1][f_x] == ' ') steps.push_back({ f_x, f_y + 1 });
	}
	if (f_y + 1 < SIZE) {
		if (f_x + 1 < SIZE and board[f_y + 1][f_x + 1] != ' ' and board[f_y + 1][f_x + 1] > 'Z') hits.insert({ f_x + 1,f_y + 1 });
		if (f_x - 1 >= 0 and board[f_y + 1][f_x - 1] != ' ' and board[f_y + 1][f_x - 1] > 'Z') hits.insert({ f_x - 1,f_y + 1 });
	}
}

void steps_p(char board[SIZE][SIZE], int f_x, int f_y, vector<vector<int>>& steps, set<vector<int>>& hits) {
	if (f_y == 6) {
		for (int i = f_y; i > f_y - 3; i--) {
			if (board[i][f_x] == ' ') steps.push_back({ f_x, i });
			else if (i != f_y) break;
		}
	}
	else {
		if (f_y - 1 >= 0 and board[f_y - 1][f_x] == ' ') steps.push_back({ f_x, f_y - 1 });
	}
	if (f_y - 1 >= 0) {
		if (f_x + 1 < SIZE and board[f_y - 1][f_x + 1] != ' ' and board[f_y - 1][f_x + 1] < 'a') hits.insert({ f_x + 1,f_y - 1 });
		if (f_x - 1 >= 0 and board[f_y - 1][f_x - 1] != ' ' and board[f_y - 1][f_x - 1] < 'a') hits.insert({ f_x - 1,f_y - 1 });
	}
}

void steps_r(char board[SIZE][SIZE], int f_x, int f_y, vector<vector<int>>& steps, set<vector<int>>& hits) {

	for (int i = f_y; i < SIZE; i++) {
		if (board[i][f_x] == ' ') steps.push_back({ f_x, i });
		else if (i != f_y) {
			if (board[f_y][f_x] > 'Z' and board[i][f_x] < 'a') hits.insert({ f_x, i });
			else if (board[f_y][f_x] < 'a' and board[i][f_x] > 'Z') hits.insert({ f_x, i });
			break;
		}
	}
	for (int i = f_y; i >= 0; i--) {
		if (board[i][f_x] == ' ') steps.push_back({ f_x, i });
		else if (i != f_y) {
			if (board[f_y][f_x] > 'Z' and board[i][f_x] < 'a') hits.insert({ f_x, i });
			else if (board[f_y][f_x] < 'a' and board[i][f_x] > 'Z') hits.insert({ f_x, i });
			break;
		}
	}
	for (int i = f_x; i < SIZE; i++) {
		if (board[f_y][i] == ' ') steps.push_back({ i, f_y });
		else if (i != f_x) {
			if (board[f_y][f_x] > 'Z' and board[f_y][i] < 'a') hits.insert({ i, f_y });
			else if (board[f_y][f_x] < 'a' and board[f_y][i] > 'Z') hits.insert({ i, f_y });
			break;
		}
	}
	for (int i = f_x; i >= 0; i--) {
		if (board[f_y][i] == ' ') steps.push_back({ i, f_y });
		else if (i != f_x) {
			if (board[f_y][f_x] > 'Z' and board[f_y][i] < 'a') hits.insert({ i, f_y });
			else if (board[f_y][f_x] < 'a' and board[f_y][i] > 'Z') hits.insert({ i, f_y });
			break;
		}
	}
}

void steps_n(char board[SIZE][SIZE], int f_x, int f_y, vector<vector<int>>& steps, set<vector<int>>& hits) {
	vector<vector<int>> tmp = {
		{f_x - 1,f_y - 2}, {f_x - 1,f_y + 2}, {f_x + 1,f_y - 2}, {f_x + 1,f_y + 2},
		{ f_x - 2,f_y + 1 }, { f_x - 2,f_y - 1 }, { f_x + 2,f_y - 1 }, { f_x + 2,f_y + 1 } };

	for (auto it : tmp) {
		if (it[0] >= 0 and it[0] < SIZE and it[1] >= 0 and it[1] < SIZE) {
			if (board[it[1]][it[0]] == ' ') steps.push_back({ it[0],it[1] });
			else if (board[f_y][f_x] > 'Z' and board[it[1]][it[0]] < 'a') hits.insert({ it[0], it[1] });
			else if (board[f_y][f_x] < 'a' and board[it[1]][it[0]] > 'Z') hits.insert({ it[0], it[1] });
		}
	}
}

void steps_b(char board[SIZE][SIZE], int f_x, int f_y, vector<vector<int>>& steps, set<vector<int>>& hits) {
	int i = f_x, j = f_y;
	while (i >= 0 and j >= 0) {
		if (board[j][i] == ' ') steps.push_back({ i, j });
		else if (j != f_y) {
			if (board[f_y][f_x] > 'Z' and board[j][i] < 'a') hits.insert({ i, j });
			else if (board[f_y][f_x] < 'a' and board[j][i] > 'Z') hits.insert({ i, j });
			break;
		}
		i--; j--;
	}

	i = f_x, j = f_y;
	while (i < SIZE and j < SIZE) {
		if (board[j][i] == ' ') steps.push_back({ i, j });
		else if (j != f_y) {
			if (board[f_y][f_x] > 'Z' and board[j][i] < 'a') hits.insert({ i, j });
			else if (board[f_y][f_x] < 'a' and board[j][i] > 'Z') hits.insert({ i, j });
			break;
		}
		i++; j++;
	}

	i = f_x, j = f_y;
	while (i >= 0 and j < SIZE) {
		if (board[j][i] == ' ') steps.push_back({ i, j });
		else if (j != f_y) {
			if (board[f_y][f_x] > 'Z' and board[j][i] < 'a') hits.insert({ i, j });
			else if (board[f_y][f_x] < 'a' and board[j][i] > 'Z') hits.insert({ i, j });
			break;
		}
		i--; j++;
	}

	i = f_x, j = f_y;
	while (i < SIZE and j >= 0) {
		if (board[j][i] == ' ') steps.push_back({ i, j });
		else if (j != f_y) {
			if (board[f_y][f_x] > 'Z' and board[j][i] < 'a') hits.insert({ i, j });
			else if (board[f_y][f_x] < 'a' and board[j][i] > 'Z') hits.insert({ i, j });
			break;
		}
		i++; j--;
	}
}

void k_check_rq(vector<int>& it, char current, char board[SIZE][SIZE]) {
	for (int i = it[0] - 1; i >= 0; i--) {
		if (current == 'k') {
			if (board[it[1]][i] == 'R' or board[it[1]][i] == 'Q') {
				it[0] = -1;
				break;
			}
			else if (board[it[1]][i] != ' ') break;
		}
		if (current == 'K') {
			if (board[it[1]][i] == 'r' or board[it[1]][i] == 'q') {
				it[0] = -1;
				break;
			}
			else if (board[it[1]][i] != ' ') break;
		}
	}
	for (int i = it[0] + 1; i < SIZE; i++) {
		if (current == 'k') {
			if (board[it[1]][i] == 'R' or board[it[1]][i] == 'Q') {
				it[0] = -1;
				break;
			}
			else if (board[it[1]][i] != ' ') break;
		}
		if (current == 'K') {
			if (board[it[1]][i] == 'r' or board[it[1]][i] == 'q') {
				it[0] = -1;
				break;
			}
			else if (board[it[1]][i] != ' ') break;
		}
	}
	for (int i = it[1] + 1; i < SIZE; i++) {
		if (current == 'k') {
			if (board[i][it[0]] == 'R' or board[i][it[0]] == 'Q') {
				it[1] = -1;
				break;
			}
			else if (board[it[1]][i] != ' ') break;
		}
		if (current == 'K') {
			if (board[i][it[0]] == 'r' or board[i][it[0]] == 'q') {
				it[1] = -1;
				break;
			}
			else if (board[i][it[0]] != ' ') break;
		}
	}
	for (int i = it[1] - 1; i >= 0; i--) {
		if (current == 'k') {
			if (board[i][it[0]] == 'R' or board[i][it[0]] == 'Q') {
				it[1] = -1;
				break;
			}
			else if (board[i][it[0]] != ' ') break;
		}
		if (current == 'K') {
			if (board[i][it[0]] == 'r' or board[i][it[0]] == 'q') {
				it[1] = -1;
				break;
			}
			else if (board[i][it[0]] != ' ') break;
		}
	}
}

void k_check_bq(vector<int>& it, char current, char board[SIZE][SIZE]) {
	int i = it[0]-1, j = it[1]-1;
	while (i >= 0 and j >= 0) {
		if (current > 'Z') {
			if (board[j][i] == 'B' or board[j][i] == 'Q') {
				it[1] = -1;
				break;
			}
			else if (board[j][i] != ' ') break;
		}
		else if (current < 'a') {
			if (board[j][i] == 'b' or board[j][i] == 'q') {
				it[1] = -1;
				break;
			}
			else if (board[j][i] != ' ') break;
		}
		i--; j--;
	}
	i = it[0] - 1; j = it[1] + 1;
	while (i >= 0 and j < SIZE) {
		if (current > 'Z') {
			if (board[j][i] == 'B' or board[j][i] == 'Q') {
				it[1] = -1;
				break;
			}
			else if (board[j][i] != ' ') break;
		}
		else if (current < 'a') {
			if (board[j][i] == 'b' or board[j][i] == 'q') {
				it[1] = -1;
				break;
			}
			else if (board[j][i] != ' ') break;
		}
		i--; j++;
	}
	i = it[0] + 1; j = it[1] - 1;
	while (i < SIZE and j >= 0) {
		if (current > 'Z') {
			if (board[j][i] == 'B' or board[j][i] == 'Q') {
				it[1] = -1;
				break;
			}
			else if (board[j][i] != ' ') break;
		}
		else if (current < 'a') {
			if (board[j][i] == 'b' or board[j][i] == 'q') {
				it[1] = -1;
				break;
			}
			else if (board[j][i] != ' ') break;
		}
		i++; j--;
	}
	i = it[0] + 1; j = it[1] + 1;
	while (i < SIZE and j < SIZE) {
		if (current > 'Z') {
			if (board[j][i] == 'B' or board[j][i] == 'Q') {
				it[1] = -1;
				break;
			}
			else if (board[j][i] != ' ') break;
		}
		else if (current < 'a') {
			if (board[j][i] == 'b' or board[j][i] == 'q') {
				it[1] = -1;
				break;
			}
			else if (board[j][i] != ' ') break;
		}
		i++; j++;
	}
}

void k_check_n(vector<int>& it, char current, char board[SIZE][SIZE]) {
	int f_x = it[0], f_y = it[1];
	vector<vector<int>> tmp = {
		{f_x - 1,f_y - 2}, {f_x - 1,f_y + 2}, {f_x + 1,f_y - 2}, {f_x + 1,f_y + 2},
		{ f_x - 2,f_y + 1 }, { f_x - 2,f_y - 1 }, { f_x + 2,f_y - 1 }, { f_x + 2,f_y + 1 } };

	for (auto i : tmp) {
		if (i[0] >= 0 and i[0] < SIZE and i[1] >= 0 and i[1] < SIZE) {
			if (current > 'Z' and board[i[1]][i[0]] == 'N' or current < 'a' and board[i[1]][i[0]] == 'n') {
				it[1] = -1;
				break;
			}
		}
	}
}
void k_check_k(vector<int>& it, char current, char board[SIZE][SIZE]) {
	int f_x = it[0], f_y = it[1];
	vector<vector<int>> tmp = {
		{f_x - 1,f_y}, {f_x - 1,f_y + 1}, {f_x - 1,f_y - 1}, {f_x + 1,f_y},
		{ f_x + 1,f_y + 1 }, { f_x + 1,f_y - 1 }, { f_x,f_y - 1 }, { f_x,f_y + 1 } };

	for (auto i : tmp) {
		if (i[0] >= 0 and i[0] < SIZE and i[1] >= 0 and i[1] < SIZE) {
			if (current > 'Z' and board[i[1]][i[0]] == 'K' or current < 'a' and board[i[1]][i[0]] == 'k') {
				it[1] = -1;
				break;
			}
		}
	}
}
void k_check_p(vector<int>& it, char current, char board[SIZE][SIZE]) {
	if (current == 'k') {
		if (it[0] - 1 >= 0 and it[1] - 1 >= 0 and board[it[1]-1][it[0]-1] == 'P') it[0] = -1;
		else if (it[0] + 1 < SIZE and it[1] - 1 >= 0 and board[it[1]-1][it[0]+1] == 'P') it[0] = -1;
	}
	else if (current == 'K') {
		if (it[0] - 1 >= 0 and it[1] + 1 < SIZE and board[it[1]+1][it[0]-1] == 'p') it[0] = -1;
		if (it[0] + 1 < SIZE and it[1] + 1 < SIZE and board[it[1]+1][it[0]+1] == 'p') it[0] = -1;
	}
}

void steps_k(char board[SIZE][SIZE], int f_x, int f_y, vector<vector<int>>& steps, set<vector<int>>& hits) {
	vector<vector<int>> tmp = {
		{f_x - 1,f_y}, {f_x - 1,f_y + 1}, {f_x - 1,f_y - 1}, {f_x + 1,f_y},
		{ f_x + 1,f_y + 1 }, { f_x + 1,f_y - 1 }, { f_x,f_y - 1 }, { f_x,f_y + 1 } };

	//for r and q
	for (auto& it : tmp) {
		k_check_rq(it, board[f_y][f_x], board);
		k_check_bq(it, board[f_y][f_x], board);
		k_check_n(it, board[f_y][f_x], board);
		k_check_k(it, board[f_y][f_x], board);
		k_check_p(it, board[f_y][f_x], board);
	}
	for (auto it : tmp) {
		if (it[0] >= 0 and it[0] < SIZE and it[1] >= 0 and it[1] < SIZE) {
			if (board[it[1]][it[0]] == ' ') steps.push_back({ it[0],it[1] });
			else if (board[f_y][f_x] > 'Z' and board[it[1]][it[0]] < 'a') hits.insert({ it[0], it[1] });
			else if (board[f_y][f_x] < 'a' and board[it[1]][it[0]] > 'Z') hits.insert({ it[0], it[1] });
		}
	}
}

bool Chess::is_Check(char color, char board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == color) {
				vector<int> it = {j,i};
				k_check_rq(it, color, board);
				k_check_bq(it, color, board);
				k_check_n(it, color, board);
				k_check_k(it, color, board);
				k_check_p(it, color, board);
				
				if (it[0] < 0 or it[1] < 0) {
					/*vector<vector<int>> steps;
					set<vector<int>> hits;
					steps_k(board, j, i, steps, hits);
					if (steps.size() == 0 and hits.size() == 0) end_fl = color;*/
					return 1;
				}
				return 0;
			}
		}
	}
}

bool Chess::step_from(string from) {
	if (from.size() != 2) return 0;

	f_y = 8 - (from[1] - '0');
	f_x = x_map[from[0]];

	if (f_x < 0 or f_x >= SIZE or f_y < 0 or f_y >= SIZE) return 0;

	for (auto it : steps) {
		board[it[1]][it[0]] = ' ';
	}
	steps.clear();
	hits.clear();

	switch (board[f_y][f_x])
	{
	case 'P':
		steps_P(board, f_x, f_y, steps, hits);
		break;
	case 'p':
		steps_p(board, f_x, f_y, steps, hits);
		break;
	case 'R':
	case 'r':
		steps_r(board, f_x, f_y, steps, hits);
		break;
	case 'N':
	case 'n':
		steps_n(board, f_x, f_y, steps, hits);
		break;
	case 'B':
	case 'b':
		steps_b(board, f_x, f_y, steps, hits);
		break;
	case 'Q':
	case 'q':
		steps_b(board, f_x, f_y, steps, hits);
		steps_r(board, f_x, f_y, steps, hits);
		break;
	case 'K':
	case 'k':
		steps_k(board, f_x, f_y, steps, hits);
		break;
	default:
		return 0;
	}

	for (auto it : steps) {
		board[it[1]][it[0]] = '.';
	}
	/*	for (auto it : hits) {
			board[it[1]][it[0]] = '+';
		}*/
	return 1;
}

bool Chess::step_to(string to) {
	if (to.size() != 2) {
		for (auto it : steps) {
			board[it[1]][it[0]] = ' ';
		}
		steps.clear();
		hits.clear();
		return 0;
	}

	int t_y = 8 - (to[1] - '0');
	int t_x = x_map[to[0]];
	if (t_x < 0 or t_x >= SIZE or t_y < 0 or t_y >= SIZE) return 0;

	if (board[t_y][t_x] == '.' or hits.find({ t_x,t_y }) != hits.end()) {
		for (auto it : steps) {
			board[it[1]][it[0]] = ' ';
		}
		board[t_y][t_x] = board[f_y][f_x];
		board[f_y][f_x] = ' ';
	}
	else {
		for (auto it : steps) {
			board[it[1]][it[0]] = ' ';
		}
		steps.clear();
		hits.clear();
		return 0;
	}
	steps.clear();
	hits.clear();

	if (board[t_y][t_x] > 'Z') {
		if (is_Check('K', board)) cout << "Black Check  ";
	}
	else if(board[t_y][t_x] < 'a') {
		if (is_Check('k', board)) cout << "White Check  ";
	}
	return 1;
}

void Chess::print_boar() {
	cout << "\n\n\n    a   b   c   d   e   f   g   h\n";
	cout << "  +---+---+---+---+---+---+---+---+\n";

	for (int i = 0; i < SIZE; i++) {
		cout << SIZE - i << " | ";
		for (int j = 0; j < SIZE; j++) {
			cout << symoles_unicode[board[i][j]];
			if (board[i][j] == 'p') cout << "| ";
			else cout << " | ";
		}
		cout << SIZE - i;
		cout << "\n  +---+---+---+---+---+---+---+---+\n";
	}
	cout << "    a   b   c   d   e   f   g   h\n";
}
