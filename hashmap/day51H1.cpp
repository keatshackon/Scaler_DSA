#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	vector<int>A = { 12, 7 };
	vector<int>B = { 7, 1, 6, 17, 2, 19, 10 };



	map<int, int>m;
	vector<int>ans;
	map<int, int>temp;

	for (int i = 0; i < B.size(); i++) {
		++m[B[i]];
	}

	for (int i = 0; i < A.size(); i++) {
		temp[A[i]]++ ;
	}

	for (int i = 0; i < B.size(); i++) {
		while (temp.count(B[i]) != 0 and temp[B[i]] > 0) {
			ans.push_back(B[i]);
			temp[B[i]]--;
		}
	}

	vector<int>res;

	for (int i = 0; i < A.size(); i++) {
		if (m.count(A[i]) == 0) {
			res.push_back(A[i]);
		}
	}

	sort(begin(res), end(res));

	for (int i = 0; i < res.size(); i++) {
		ans.push_back(res[i]);
	}

	// return ans;

	return 0;
}


