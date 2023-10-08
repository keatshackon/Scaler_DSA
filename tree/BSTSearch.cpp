#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// PRINTING BST USING INORDER TRAVERSAL
void print(TreeNode *root) {
	if (root == NULL) return;

	print(root->left);
	cout << root->val << " ";
	print(root->right);
}

// BST SAERCH
int solve(TreeNode *root, int k) {

	if (root == NULL) {
		return -1;
	}
	if (root->val == k) {
		return 1;
	} else if (root->val > k) {
		return solve(root->left, k);
	} else {
		return solve(root->right, k);
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
	cout << "In Inorder: ";
	print(root);
	cout << "\n\n\n";
	//====================================================

	int k = 17;

	if (solve(root, k) == 1) {
		cout << k << " Found\n";
	} else {
		cout << k << " Not Found\n";
	}


	return 0;
}
