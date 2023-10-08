#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// preorder Traversal, Doing For Testing purpose.
void print(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	cout << root->val << " ";
	print(root->left);
	print(root->right);
}


// Preorder Traversal without Recusion.
void solve(TreeNode *A) {

	stack<TreeNode*>s;
	TreeNode *cur = A;

	while (!s.empty() or cur != NULL) {

		while (cur != NULL) {
			cout << cur->val << " ";
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		s.pop();
		cur = cur->right;
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


	// TRAVERSE THE TREE using Inorder Traversal
	cout << "\nTraversing  : ";
	print(root);
	cout << "\n\n";

	cout << "Iterative version  preorder Traversal : ";
	solve(root);
	cout << "\n";

	return 0;
}