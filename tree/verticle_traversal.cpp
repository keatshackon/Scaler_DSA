#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {

	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// testing tree construction
void print(TreeNode *root) {

	queue<TreeNode*>q;
	q.push(root);

	while (!q.empty()) {
		TreeNode *temp = q.front();
		cout << temp->val << " ";
		q.pop();
		if (temp->left != NULL) {
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}
}

void solve(TreeNode *root) {

	queue<pair<int, TreeNode*>>q;
	q.push({0, root});
	unordered_map<int, vector<TreeNode*>> m;

	int minn = INT_MAX, maxx = INT_MIN;

	while (!q.empty()) {
		pair<int, TreeNode*> temp = q.front();
		int idx = temp.first;
		TreeNode* t = temp.second;
		m[idx].push_back(t);
		q.pop();

		minn = min(minn, idx);
		maxx = max(maxx, idx);

		if (t->left != NULL) {
			q.push({idx - 1, t->left});
		}

		if (t->right != NULL) {
			q.push({idx + 1, t->right});
		}
	}

	// cout << minn << " " << maxx << "\n";

	for (int i = minn; i <= maxx; i++) {
		cout << i << " : ";
		for (auto q : m[i]) {
			cout << q ->val << " ";
		}
		cout << "\n";
	}
}

int main() {

	TreeNode  *root = new TreeNode(3);
	root->left = new TreeNode(7);
	root->right = new TreeNode(4);
	root->right->left =  new TreeNode(14);
	root->right->right = new TreeNode(18);
	root->left->left =  new TreeNode(9);
	root->left->left->left =  new TreeNode(12);
	root->left->left->right =  new TreeNode(19);


	// priting tree
	print(root);
	cout << "\n\n";


	solve(root);

	return 0;
}