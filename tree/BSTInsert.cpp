#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// LEVEL ORDER TRAVERSAL
void print(TreeNode *root) {

	if (root == NULL) return;

	queue<TreeNode*>q;
	q.push(root);

	while (!q.empty()) {
		TreeNode *temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
}

void solve(TreeNode *root, int k) {

	if (root == NULL) return;
	TreeNode *pre = NULL;

	while (root != NULL) {
		pre = root;
		if (root->val > k) {
			root = root->left;
		} else {
			root = root->right;
		}
	}
	TreeNode *add = new TreeNode(k);
	if (k > pre->val) {
		pre->right = add;
	} else {
		pre->left = add;
	}
}


int main() {

	TreeNode *root = new TreeNode(8);
	root->left = new TreeNode(4);
	root->right = new TreeNode(13);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(7);
	root->left->right->left = new TreeNode(6);
	root->right->left = new TreeNode(10);
	root->right->right = new TreeNode(15);
	root->right->right->right = new TreeNode(17);

	// Traversal
	cout << "In Level Order: ";
	print(root);
	cout << "\n\n\n";
	//====================================================

	solve(root, 9);

	print(root);

	return 0;
}