#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}

int solve(TreeNode *A, int ma) {

	if (A == NULL) return 0;

	int res = A -> val >  ma ? 1 : 0;

	res += solve(A->left, max(ma, A->val));
	res += solve(A->right, max(ma, A->val));
	return res;
}


int main() {

	TreeNode  *root = new TreeNode(11);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(3);
	root->right = new TreeNode(20);
	root->right->right =  new TreeNode(14);
	root->right->right->left = new TreeNode(5);


	// TRAVERSE THE TREE using Inorder Traversal
	cout << "\nTraversing : ";
	print(root);
	cout << "\n\n";


	int ans = solve(root, -10000);
	cout << ans;

	return 0;
}

