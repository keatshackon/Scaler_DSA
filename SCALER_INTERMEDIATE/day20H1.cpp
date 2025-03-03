#include<bits/stdc++.h>
using namespace std;
#define ll long long


bool cmp(int x, int y) {

	string s1 = to_string(x);
	string s2 = to_string(y);

	string res1 = s1 + s2;
	string res2 = s2 + s1;

	if (res1 > res2) {
		return true;
	}
	return false;
}


int main() {

	vector<int> A = {8, 89};
	// vector<int> A = {2, 3, 9, 0};

	string ans = "";

	sort(A.begin(), A.end(), cmp);


	int t = 0;
	while (t < A.size()) {
		if (A[t] != 0) {
			break;
		}
		t++;
	}
	while (t < A.size()) {
		ans += to_string(A[t]);
		t++;
	}
	if (ans == "") {
		string a = "";
		a += "0";
		cout << a;
	}
	// return ans;

	cout << ans;

}