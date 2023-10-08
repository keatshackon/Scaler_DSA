#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	int A = 4;
	int B = 3;
	vector<int>C = {2, 1, 1};

	priority_queue <int, vector<int>, greater<int>> pq1;
	priority_queue <int> pq2;

	int n = C.size();

	for (int i = 0; i < n; i++) {
		pq1.push(C[i]);
		pq2.push(C[i]);
	}



	int maxi = 0, mini = 0;

	int A1 = A;


	while (A and !pq1.empty()) {

		int cur = pq1.top();
		pq1.pop();
		mini += cur;
		int temp = cur - 1;
		A--;
		if (temp > 0)
			pq1.push(temp);
	}
	cout << mini << " ";


	while (A1 and !pq2.empty()) {

		int cur = pq2.top();
		pq2.pop();
		maxi += cur;
		int temp = cur - 1;
		A1--;
		if (temp > 0)
			pq2.push(temp);
	}

	cout << maxi << "\n";

	return 0;
}