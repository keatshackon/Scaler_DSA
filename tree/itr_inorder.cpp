#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Inorder Traversal, Doing For Testing purpose.
void print(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}


// Inorder Traversal without Recusion
void solve(TreeNode *A) {

	stack<TreeNode*>s;
	s.push(A);
	TreeNode *cur = A->left;

	while (!s.empty() or cur != NULL) {

		while (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		s.pop();
		cout << cur->val << " ";
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

	cout << "Iterative version  Inorder Traversal : ";
	solve(root);
	cout << "\n";

	return 0;
}