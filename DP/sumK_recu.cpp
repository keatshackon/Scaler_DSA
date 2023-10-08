#include <bits/stdc++.h>
using namespace std;
#define ll long long



vector<int>v =  {1, 2, 1};
int f = 0;

void solve(int i, vector<int>&ds, int &sum, int &cnt, int &n) {

	if (i == n) {
		int ans = 0;
		for (auto q : ds) {
			ans += q;
		}
		cout << "\n";
		if (sum == ans) {
			for (auto q : ds) {
				cout << q << " ";
			}
			cout << "\n";
			cnt++;
			f = 1;
		}
		return;
	}
	// Picking the Upcoming index;
	ds.push_back(v[i]);
	// sum += v[i];
	solve(i + 1, ds, sum, cnt, n);
	if (f == 1) {
		return;
	}

	//Not Picking the index
	ds.pop_back();
	// sum -= v[i];
	solve(i + 1, ds, sum, cnt, n);
	if (f == 1) {
		return;
	}
}


int main() {

	int sum = 2;
	int cnt = 0;
	int n = v.size();
	cout << "size : " << n << "\n";

	vector<int>ds;

	solve(0, ds, sum, cnt, n);
	cout << "Total Number Of Ways To Get Given Sum: ";
	cout << cnt << "\n";

	return 0;
}