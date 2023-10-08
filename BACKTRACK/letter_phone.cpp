#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int idx, map<char, string>&m, string &A, string  &ds, vector<string>&ans) {

	if (idx == A.size()) {
		ans.push_back(ds);
		return;
	}

	string k = m[A[idx]];
	for (int i = 0; i < k.length(); i++) {
		ds += k[i];
		solve(idx + 1, m, A, ds, ans);
		ds.pop_back();
	}
}

int main() {


	string A = "012";

	map<char, string> m = {{'0', "0"},
		{'1', "1"}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
		{'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"},
		{'9', "wxyz"}
	};


	vector<string>ans;
	string ds = "";
	int idx = 0;

	solve(idx, m, A, ds, ans);


	for (auto q : ans) {
		cout << q << " ";
	}


	return 0;
}