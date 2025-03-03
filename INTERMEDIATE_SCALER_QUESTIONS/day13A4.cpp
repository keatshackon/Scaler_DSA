#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<vector<int>> A = {{1, 2}
	};

	vector<vector<int>> B = {{5, 6},
		{7, 8}
	};

	vector<vector<int>>ans;

	for (int i = 0; i < A.size(); i++) {
		vector<int>temp;
		for (int j = 0; j < B[0].size(); j++) {
			int sum = 0;
			for (int k = 0; k < B.size(); k++) {
				sum += A[i][k] * B[k][j];
			}
			temp.push_back(sum);
		}
		ans.push_back(temp);
	}

	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;

}