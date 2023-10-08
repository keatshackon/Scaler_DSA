#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct Node {

	struct Node *left;
	struct Node *right;
	int val;
	Node(int x): val(x), left(NULL), right(NULL) {}

};

int main() {

	Node *root = new Node(10);


	if (root == NULL) {
		cout << 0 << "\n";
		return 0;
	}

	queue<Node*>q;
	q.push(root);

	int ans = 0;
	int sum = 0;

	while (!q.empty()) {

		int n = q.size();
		while (n--) {
			sum += q.front()->val;
			if (q.front()->left != NULL) {
				q.push(q.front()->left);
			}

			if (q.front()->right != NULL) {
				q.push(q.front()->right);
			}
			q.pop();
		}
		ans = sum;
		sum = 0;
	}

	cout << ans << "\n";

	return 0;
}