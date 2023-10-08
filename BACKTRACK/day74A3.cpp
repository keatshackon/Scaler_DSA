#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int s1, int s2, int row, int col, int cnt,
           vector<vector<int>>&A, vector<vector<int>>&vis, int &ans) {


	if (A[s1][s2] == 2) {
		if (cnt == 0) {
			ans++;
		}
		return;
	}
	//          r  d  l   u
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	for (int i = 0; i < 4; i++) {
		int x = s1 + dx[i];
		int y = s2 + dy[i];

		if (x >= 0 and x < row and y >= 0 and y < col and A[x][y] != -1
		        and vis[x][y] == 0) {

			vis[x][y] = 1;
			solve(x, y, row, col, cnt - 1, A, vis, ans);
			vis[x][y] = 0;
		}
	}
}


int main() {


	vector<vector<int>>A = {
		{1, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 2, -1}
	};

	int s1 = -1, s2 = -1;

	int row = A.size();
	int col = A[0].size();
	int cnt = 0;

	vector<vector<int>>vis(row, vector<int>(col, 0));


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (A[i][j] == 1) {
				s1 = i;
				s2 = j;
			} else if (A[i][j] == 0) {
				cnt++;
			}
		}
	}

	int ans = 0, k = 0;;


	cout << s1 << " " << s2 << "\n";
	cout << cnt << "\n";


	solve(s1, s2, row, col, cnt + 1, A, vis, ans);

	cout << ans;


	return 0;
}