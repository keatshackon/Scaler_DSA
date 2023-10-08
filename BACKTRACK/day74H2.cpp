#include <bits/stdc++.h>
using namespace std;
#define ll long long



void solve(int idx, int n, string &A, map<char, string>&m, string  &ds, vector<string>&ans) {

	if (idx == n) {
		ans.push_back(ds);
		return ;
	}

	string s = m[A[idx]];
	int len = s.length();
	for (int i = 0; i < len; i++) {
		ds += s[i];
		solve(idx + 1, n, A, m, ds, ans);
		ds.pop_back();
	}
}


int main() {


	string A = "23";

	map<char, string> m;

	m['0'] = "0";
	m['1'] = "1";
	m['2'] = "abc";
	m['3'] = "def";
	m['4'] = "ghi";
	m['5'] = "kjl";
	m['6'] = "mno";
	m['7'] = "pqrs";
	m['8'] = "tuv";
	m['9'] = "wxyz";


	vector<string>ans;
	string ds;
	int n = A.length();
	int idx = 0;
	solve(idx, n, A, m, ds, ans);

	for (auto q : ans) {
		cout << q << " ";
	}


	return 0;
}