#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	vector<int> A = {0};
	int car = 1;
	vector<int>ans;
	vector<int>res;

	for (int i = A.size() - 1; i >= 0; i--) {
		int temp = car + A[i];
		if (temp >= 10) {
			ans.push_back(temp % 10);
			car = temp / 10;
		} else {
			ans.push_back(temp);
			car = 0;
		}
	}
	if (car != 0) {
		ans.push_back(car);
	}
	reverse(ans.begin(), ans.end());

	int k = 0;
	int f = 0; n
	while (k < ans.size()) {
		if (ans[k] == 0 and f == 0) {
			k++;
		} else {
			f = 1;
			res.push_back(ans[k]);
			k++;
		}
	}

	for (auto q : res) {
		cout << q << " ";
	}
	return 0;
}