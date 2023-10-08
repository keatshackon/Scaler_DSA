#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> left_smallest(vector<int>&A) {

	int len = A.size();
	vector<int>ans(len);
	stack<pair<int, int>>st;
	st.push({A[0], 0});
	ans[0] = -1;


	for (int i = 1; i < len; i++) {
		if (A[i] > st.top().first) {
			st.push({A[i], i});
			ans[i] = i - 1;
		} else {
			while (!st.empty() and A[i] <= st.top().first) {
				st.pop();
			}
			if (st.empty()) {
				ans[i] = -1;
			} else {
				ans[i] = st.top().second;
			}
			st.push({A[i], i});
		}
	}
	return ans;
}

vector<int> right_smallest(vector<int>&A) {

	int len = A.size();

	vector<int>ans(len);
	stack<pair<int, int>>st;
	st.push({A[len - 1], len - 1});
	ans[len - 1] = len;


	for (int i = len - 2; i >= 0 ; i--) {
		if (A[i] > st.top().first) {
			st.push({A[i], i});
			ans[i] = i + 1;
		} else {
			while (!st.empty() and A[i] <= st.top().first) {
				st.pop();
			}
			if (st.empty()) {
				ans[i] = len;
			} else {
				ans[i] = st.top().second;
			}
			st.push({A[i], i});
		}
	}
	return ans;
}

int main() {

	vector<int>A = {6, 57, 59, 57, 35, 36, 88, 28, 47, 77, 20, 97, 80, 90, 5, 49, 47  };
	int len = A.size();

	vector<int>ls = left_smallest(A);
	vector<int>rs = right_smallest(A);

	for (auto q : ls) {
		cout << q << " ";
	}
	cout << "\n";
	for (auto q : rs) {
		cout << q << " ";
	}
	cout << "\n";

	int ans = 0;

	for (int i = 0; i < len; i++) {
		int temp = ((rs[i] - ls[i]) - 1) * A[i];
		ans = max(ans, temp);
	}

	cout << ans << "\n";
	return 0;
}