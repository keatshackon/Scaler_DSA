#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	vector<vector<int>>A = {{10, 20, 30}, {5, 10, 20}, { 2, 4, 6}};

	vector<vector<int>>ans;

	for (int i = 0; i < A.size(); i++) {
		vector<int>temp;
		temp.push_back(A[i][0]);
		int res = A[i][0];
		for (int j = 1; j < A.size(); j++) {
			res += A[i][j];
			temp.push_back(res);

		}
		ans.push_back(temp);
	}

	for (int i = 0; i < A.size(); i++) {
		for (int j = 1; j < A.size(); j++) {
			ans[j][i] = ans[j - 1][i] + ans[j][i];
		}
	}



	// printing prefix matrics element
	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}