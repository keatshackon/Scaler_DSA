#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<string>A = {"hello", "scaler", "interviewbit"};
	string B =  "adhbcfegskjlponmirqtxwuvzy";


	unordered_map<char, int> m;

	for (int i = 0; i < B.length(); i++) {
		m[B[i]] = i;
	}

	for (int i = 1; i < A.size(); i++) {
		string temp1 = A[i - 1];
		string temp2 = A[i];

		int x = 0;
		int y = 0;

		while (x < temp1.length() and y < temp2.length() and temp2[y] == temp1[x]) {
			x++;
			y++;
		}

		if (x < temp1.length() and y < temp2.length() and  m[temp1[x]] > m[temp2[y]]) {
			cout << "falseee";
			return false;
		} else if (y == temp2.length() and x < temp1.length()) {
			cout << "faslew";
			return false;
		}

	}
	cout << "true";
	return 0;
}