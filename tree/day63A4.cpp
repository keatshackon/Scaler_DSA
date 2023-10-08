#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {

	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// Testing Tree Construction
void print(TreeNode *root) {

	queue<TreeNode*>q;
	q.push(root);

	while (!q.empty()) {
		TreeNode *temp = q.front();
		cout << temp->val << " ";
		q.pop();
		if (temp->left != NULL) {
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}
}

int solve(TreeNode *root) {

	if (root == NULL) {
		return 1;
	}

	int h1 = 1 + solve(root->left);
	int h2 = 1 + solve(root->right);

	if (abs(h1 - h2) > 1) {
		return 0;
	}

	return 1 + max(h1, h2);
}


int main() {

	TreeNode  *root = new TreeNode(3);
	root->left = new TreeNode(7);
	root->right = new TreeNode(4);
	root->right->left =  new TreeNode(14);
	root->right->right = new TreeNode(18);
	root->left->left =  new TreeNode(9);
	root->left->left->left =  new TreeNode(12);
	root->left->left->left->left =  new TreeNode(100);
	root->left->left->right =  new TreeNode(19);


	// Priting tree to ensure the construction of tree
	cout << "Traversing :";
	print(root);
	cout << "\n\n";

	int s = solve(root);
	if (s == 0) {
		cout << "no\n";
	} else {
		cout << "yes\n";
	}


	return 0;
}