#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void postOrder_traversal(TreeNode *root) {

	if (root == NULL) return;

	postOrder_traversal(root->left);
	postOrder_traversal(root->right);
	cout << root->val << " ";
}


void preOrder_traversal(TreeNode *root) {

	if (root == NULL) return;

	cout << root->val << " ";
	preOrder_traversal(root->left);
	preOrder_traversal(root->right);
}

void inOrder_traversal(TreeNode *root) {

	if (root == NULL) return;

	inOrder_traversal(root->left);
	cout << root->val << " ";
	inOrder_traversal(root->right);
}


int main() {

	TreeNode  *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left =  new TreeNode(15);
	root->right->right = new TreeNode(7);


	// TRAVERSE THE TREE using Inorder Traversal
	cout << "\nInorder Traversing  : ";
	inOrder_traversal(root);
	cout << "\n\n";


	// TRAVERSE THE TREE using preOrder Traversal
	cout << "\nPreOrder Traversing  : ";
	preOrder_traversal(root);
	cout << "\n\n";


	// TRAVERSE THE TREE using postOrder Traversal
	cout << "\nPost Traversing  : ";
	postOrder_traversal (root);
	cout << "\n\n";


	return 0;
}
