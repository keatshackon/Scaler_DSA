#include <bits/stdc++.h>
using namespace std;
#define ll long long

int size = -1;
vector<int>st;

void print() {
	if (size <= -1) {
		cout << "Nothing is present\n";
	}
	for (int i = size; i >= 0 ; i--) {
		cout << st[i] << " ";
	}
	cout << "\n";
}

void pop() {
	size--;
	st.pop_back();
}

int top() {
	if (size > -1) {
		return st[size];
	} else {
		cout << "Element is Not present\n";
	}
}

void push(int val) {
	// if ((size + 1) == (int)st.size()) {
	// 	cout << "Can't Insert, Stack Size Full\n";
	// 	return;
	// }
	size++;
	st.push_back(val);
}

int main() {

	int n;
	// cout << "Input The Stack Size : ";
	// cin >> n;
	vector<vector<int>>q = {{1, 2}, {1, 22}, {1, 23}, {3}, {2}, {2}, {1, 40}, {3}, {4}};
	for (int i = 0; i < q.size(); i++) {
		if (q[i][0] == 1) {
			push(q[i][1]);
		} else if (q[i][0] == 2) {
			pop();
		} else if (q[i][0] == 3) {
			print();
		} else {
			cout << top();
		}
	}

	return 0;
}