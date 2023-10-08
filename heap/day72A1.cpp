#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	vector<int>A = {5, 17, 100, 11};


	priority_queue<int>max_heap;
	priority_queue<int, vector<int>, greater<int>>min_heap;

	int n = A.size();
	int i = 0;

	while (i < n) {

		if (max_heap.size() == 0) {
			max_heap.push(A[i]);
		} else if (max_heap.top() > A[i]) {
			max_heap.push(A[i]);
			if (abs(max_heap.size() - min_heap.size()) > 1) {
				min_heap.push(max_heap.top());
				max_heap.pop();
			}
		} else {
			min_heap.push(A[i]);
			if (abs(min_heap.size() - max_heap.size()) > 1) {
				max_heap.push(min_heap.top());
				min_heap.pop();
			}
		}

		if (!min_heap.empty() and min_heap.size() > max_heap.size()) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}

		i++;
		cout << max_heap.top() << " ";
	}

	return 0;
}