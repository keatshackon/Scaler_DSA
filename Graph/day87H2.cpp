#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	int A = 15;
	int B = 18;
	int C = 29;
	vector<int>D = {11, 2, 2, 6, 2, 8, 9, 3, 14, 15, 4, 14, 8, 7, 8, 6, 2, 12};
	vector<int>E = {2, 1, 1, 2, 1, 1, 7, 3, 2, 13, 2, 1, 6, 1, 7, 1, 2, 10 };
	vector<int>F = {8337, 6651, 29, 7765, 3428, 5213, 6431, 2864, 3137, 4024, 8169, 5013, 7375, 3786, 4326, 6415, 8982, 6864 };
	vector<int>G = {6, 2, 1, 15, 12, 2, 14, 10, 13, 15, 15, 4, 8, 7, 9, 4, 15, 13, 12, 5, 2, 10, 1, 11, 14, 7, 3, 13, 12};
	vector<int>H = {5, 2, 15, 13, 6, 2, 8, 6, 3, 13, 15, 3, 1, 1, 4, 4, 5, 8, 1, 3, 1, 10, 15, 9, 2, 1, 1, 10, 2};

	vector<vector<ll>>g(A + 1, vector<ll>(A + 1, 1e10));

	for (int i = 0; i < B; i++) {
		g[D[i]][E[i]] = F[i];
		g[E[i]][D[i]] = F[i];
	}

	for (int i = 1; i <= A; i++) {
		g[i][i] = 0;
	}

	// for (auto q : g) {
	// 	for (auto w : q) {
	// 		cout << w << " ";
	// 	}
	// 	cout << "\n";
	// }

	for (int k = 1; k <= A; k++) {
		for (int i = 1; i <= A; i++) {
			for (int j = 1; j <= A; j++) {
				g[i][j] = (ll)min((ll)g[i][j],
				                  (ll)g[i][k] + (ll)g[k][j]);
			}
		}
	}

	// cout << "\n\n";
	// for (auto q : g) {
	// 	for (auto w : q) {
	// 		cout << w << " ";
	// 	}
	// 	cout << "\n";
	// }

	vector<ll>ans;

	for (int i = 0; i < C; i++) {
		if (g[G[i]][H[i]] == 1e10) {
			ans.push_back(-1);
		} else {
			ans.push_back(g[G[i]][H[i]]);
		}
	}

	for (auto q : ans) {
		cout << q << " ";
	}

	return 0;
}
