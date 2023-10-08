#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<int>q;
int my_size = 0;
int r = -1, f = -1;


void enqueue(int val) {
	if (my_size == (q.size())) {
		cout << "Size Is Full\n";
		return;
	}
	r = (r + 1) % q.size();
	my_size++;
	q[r] = val;
}

void dequeue() {
	if (my_size < 0 ) {
		cout << "Nothing Is Present To Delete\n";
		return;
	}
	f = (f + 1) % q.size();
	my_size--;
}

int front() {
	if (my_size <= q.size() and my_size > 0) {
		return q[(f + 1) % q.size()];
	}
	return INT_MIN;

}

int main() {

	int n = 3;
	q.resize(n);
	vector<vector<int>>query = {{1, 2}, {1, 12}, {1, 90}, {2}, {3}, {2}, {3}, {2}, {3}};

	for (int i = 0; i < query.size(); i++) {
		if (query[i][0] == 1) {
			enqueue(query[i][1]);
		} else if (query[i][0] == 2) {
			dequeue();
		} else {
			int ans = front();
			if (ans != INT_MIN) {
				cout << ans << "\n";
			} else {
				cout << "NONE" << "\n";
			}
		}
	}
	return 0;
}