#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int> A = { 43, 35, 25, 5, 34, 5, 8, 7 };
	int B = 6;

	int i = 0;
	int j = B - 1;

	int len = A.size();

	vector<int>ans;

	while (j >= 0 ) {
		ans.push_back(A[j]);
		j--;
	}

	j = B;
	while (j < len) {
		ans.push_back(A[j]);
		j++;
	}

	// return ans;
	return 0;
}