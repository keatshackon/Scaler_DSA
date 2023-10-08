#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//Printing Tree Using Inorder
void print(TreeNode *root) {

	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->val << " ";
	print(root->right);

}

TreeNode* solve(TreeNode *root, int A, int B) {

	if (root == NULL) {
		return NULL;
	}
	if (root->val >= A and root->val >= B) {
		solve(root->left, A, B);
	} else if (root->val <= A and root->val <= B) {
		solve(root->right, A, B);
	} else {
		return root;
	}
}

int height_distance(TreeNode* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (root->val == k) {
		return 0;
	} else if (root->val > k) {
		return 1 + height_distance(root->left, k);
	} else if (root->val < k) {
		return 1 + height_distance(root->right, k);
	}
}

int main() {

	TreeNode  *root = new TreeNode(15);
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


	//Checking Tree Construction
	print(root);
	cout << "\n";

	int A = 11;
	int B = 20;
	TreeNode* LCA = solve(root, A, B);

	cout << "LCA of " << A << " And " << B << " = " << LCA->val << "\n";

	cout << height_distance(LCA, A) + height_distance(LCA, B);


	return 0;
}