#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *root) {

	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}

bool solve(TreeNode *root, int k) {

	if (root == NULL) {
		return false;
	}
	if (root->val == k) {
		return true;
	}
	bool h1 = solve(root->left, k);
	if (h1 == true) return true;
	bool h2  = solve(root->right, k);

	return h1 or h2;
}



int main() {

	TreeNode  *root = new TreeNode(15);
	root->left = new TreeNode(10);
	root->right = new TreeNode(13);
	root->left->left =  new TreeNode(5);
	root->left->left->left =  new TreeNode(3);
	root->left->left->right =  new TreeNode(8);
	root->left->right =  new TreeNode(24);
	root->left->right->left =  new TreeNode(11);
	root->right->left =  new TreeNode(18);
	root->right->right = new TreeNode(35);
	root->right->left->left =  new TreeNode(16);
	root->right->left->right =  new TreeNode(20);
	root->right->left->right->right =  new TreeNode(22);


	//Checking Tree Construction
	print(root);
	cout << "\n\n";

	int s = solve(root, 22);
	cout << s;
	return 0;
}