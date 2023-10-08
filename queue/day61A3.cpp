#include <bits/stdc++.h>
using namespace std;
#define ll long long

stack<pair<int, int>>st;

void push(int x) {

	if (!st.empty()) {
		st.push({x, min(st.top().second, x)});
	} else {
		st.push({x, x});
	}
}

void pop() {

	if (st.empty()) {
		return;
	}
	st.pop();
}

int top() {

	if (!st.empty() ) {
		return st.top().first;
	} else {
		return -1;
	}
}

int getMin() {

	if (!st.empty()) {
		return st.top().second;
	} else {
		return -1;
	}
}
int main() {

	int n = 0, x = 0;

	int qurery = 7;

	while (qurery--) {
		cin >> n;

		if (n == 1) {
			cin >> x;
			push(x);
		} else if (n == 2) {
			cout << top();
		} else if (n == 3) {
			pop();
		} else {
			cout << getMin();
		}
	}



	return 0;
}