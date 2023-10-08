#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isValid(vector<vector<int>>& board, int r, int c, int ch) {
	for (int i = 0; i < 9; i++) {
		if (board[i][c] == ch)
			return false;
		if (board[r][i] == ch)
			return false;
		if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch)
			return false;

	}
	return true;
}

// bool solve(vector<vector<int>>&board) {

// 	for (int i = 0; i < 9; i++) {
// 		for (int j = 0; j < 9; j++) {
// 			if (board[i][j] == 0) {
// 				for (char c = 1; c <= 9; c++) {
// 					if (isValid(board, i, j, c)) {
// 						board[i][j] = c;
// 						if (solve(board))
// 							return true;
// 						else {
// 							board[i][j] = 0;
// 						}

// 					}
// 				}
// 				return false;
// 			}
// 		}
// 	}
// 	return true;
// }




bool solve2(int idx, vector<vector<int>>&board) {

	if (idx == 81) {
		return true;
	}
	int x = idx / 9;
	int y = idx % 9;
	if (board[x][y] != 0) {
		return solve2(idx + 1, board);

	} else {
		for (int k = 1; k <= 9; k++) {

			if (isValid(board, x, y, k)) {
				board[x][y] = k;
				if (solve2(idx + 1, board)) {
					return true;
				}
				board[x][y] = 0;
			}
		}
		return false;
	}
}

int main() {


	vector<vector<int>>A = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	int idx = 0;
	vector<vector<int>>ans;


	for (auto q : A) {
		for (auto w : q) {
			cout << w << ", ";
		}
		cout << "\n";
	}

	cout << "\n\n";

	solve2(idx, A);


	for (auto q : A) {
		for (auto w : q) {
			cout << w << ", ";
		}
		cout << "\n";
	}


	return 0;
}