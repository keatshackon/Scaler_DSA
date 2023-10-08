#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void print(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}
// NEED TO DRY RUN
TreeNode* solve(TreeNode *root, TreeNode* k, TreeNode* l) {

	if (root == NULL or k == root or l == root) {
		return root;
	}

	TreeNode *left = solve(root->left, k, l);
	TreeNode *right = solve(root->right, k, l);

	if (left == NULL) {
		return right;
	} else if (right == NULL) {
		return left;
	} else {
		return root;
	}
}

int main() {

	TreeNode *root = new TreeNode(15);
	root->left = new TreeNode(10);
	root->right = new TreeNode(24);
	root->left->left =  new TreeNode(5);
	root->left->left->left =  new TreeNode(3);
	root->left->left->right =  new TreeNode(8);
	root->left->right =  new TreeNode(13);
	root->left->right->left =  new TreeNode(11);
	root->right->left =  new TreeNode(18);
	root->right->right = new TreeNode(35);
	root->right->left->left =  new TreeNode(16);
	root->right->left->right =  new TreeNode(20);
	root->right->left->right->right =  new TreeNode(22);

	// Checking Tree Construction
	print(root);
	cout << "\n\n";

	TreeNode* l = root->left->left;
	TreeNode* k = root->left->left->right;
	TreeNode* ans = solve(root, l, k);

	cout << "The LCA Of " << l->val << " AND " << k->val << " IS: " << ans->val;


	return 0;
}