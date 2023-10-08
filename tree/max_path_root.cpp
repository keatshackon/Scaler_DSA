#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// Checking The construction of Tree
void print(TreeNode* root) {

	queue<TreeNode*>q;
	q.push(root);
	while (q.size()) {
		TreeNode* temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
	}
}

int solve(TreeNode *root) {

	if (root == NULL) {
		return 0;
	}

	int h1 = solve(root->left);
	int h2 = solve(root->right);

	return max(root->val , root->val + max(h1, h2));
}

int main() {

	TreeNode* root = new TreeNode(14);
	root->left = new TreeNode(6);
	root->right =  new TreeNode(8);
	root->left->left  = new TreeNode(4);
	root->left->right = new TreeNode(-2);
	root->left->right->left = new TreeNode(7);
	root->right->left  = new TreeNode(-4);
	root->right->right  = new TreeNode(2);
	root->right->right->left = new TreeNode(10);


	// Checking the construction
	print(root);
	cout << "\n\n";

	cout << solve(root);
	return 0;
}