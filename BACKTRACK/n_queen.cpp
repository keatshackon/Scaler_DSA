#include <bits/stdc++.h>
using namespace std;
#define ll long long

// bool isValid(int x, int y, vector<vector<string>>&board) {

// 	int i = x;
// 	int j = y;
// 	int n = board.size();

// 	while (i >= 0) {
// 		if (board[i][j] == "Q") {
// 			return false;
// 		}
// 		i--;
// 	}
// 	i = x;
// 	j = y;
// 	while (j >= 0 and i >= 0) {
// 		if (board[i][j] == "Q") {
// 			return false;
// 		}
// 		j--;
// 		i--;
// 	}
// 	i = x;
// 	j = y;
// 	while (j < n and i >= 0) {
// 		if (board[i][j] == "Q") {
// 			return false;
// 		}
// 		j++;
// 		i--;
// 	}

// 	return true;
// }



void solve(int idx, int n, vector<bool>&col, vector<bool>&diagonal,
           vector<bool>&anti_diagonal, vector<vector<string>>&A,
           vector<vector<string>>&ans) {

	if (idx == n) {
		vector<string>temp;
		for (auto q : A) {
			string s = "";

			for (auto w : q) {
				s += w;
			}
			temp.push_back(s);
		}
		ans.push_back(temp);
		return;
	}

	for (int i = 0; i < n; i++) {

		if (col[i] == true or diagonal[idx - i + n] == true
		        or anti_diagonal[idx + i] == true) {
			continue;
		}
		A[idx][i] = "Q";
		col[i] = true;
		anti_diagonal[idx + i] = true;
		diagonal[idx - i + n] = true;
		solve(idx + 1, n, col, diagonal, anti_diagonal, A, ans);
		A[idx][i] = ".";
		col[i] = false;
		anti_diagonal[idx + i] = false;
		diagonal[idx - i + n] = false;
	}
}


int main() {


	int n = 4;
	vector<vector<string>>board(n, vector<string>(n, "."));


	vector<vector<string>>ans;
	vector<bool>col(n + n, false);
	vector<bool>diagonal(n + n, false);
	vector<bool>anti_diagonal(n + n, false);


	solve(0, n, col, diagonal, anti_diagonal, board, ans);


	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}