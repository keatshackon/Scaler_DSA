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

void solve(TreeNode *root, int lable, map<int, set<int>>&m) {

	if (root == NULL) {
		return;
	}
	m[lable].insert(root->val);
	solve(root->left, lable - 1, m);
	solve(root->right, lable + 1, m);
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
	cout << "Traversing :";
	print(root);
	cout << "\n\n";

	map<int, set<int>>m;
	int size = 0;
	solve(root, size, m);


	//printing verticle traversal
	for (auto q : m) {
		cout << q.first << " : ";
		for (auto w : q.second) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}