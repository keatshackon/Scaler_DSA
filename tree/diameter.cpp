#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// print The Tree
void print(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}

int solve(TreeNode *root, int &diameter) {

	if (root == NULL) {
		return 0;
	}
	int h1 = solve(root->left, diameter);
	int h2 = solve(root->right, diameter);

	diameter = max(diameter, h1 + h2);

	return 1 + max(h1, h2);
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

	// Checking the Construction Of tree
	print(root);
	cout << "\n\n";

	int ans = solve(root, ans);

	cout << "The Diameter of the tree : " << ans << "\n";

	return 0;
}