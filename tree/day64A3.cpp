#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// PRINTNG TREE USING LEVEL ORDER TRAVERSAL
void print(TreeNode *root) {

	if (root == NULL) return;

	print(root->left);
	cout << root->val << " ";
	print(root->right);
}

TreeNode* solve(vector<int> &v, int start, int end) {

	if (end < start) {
		return NULL;
	}

	int mid = (start + end) / 2;
	TreeNode *x = new TreeNode(v[mid]);
	x->left = solve(v, start, mid - 1);
	x->right = solve(v, mid + 1, end);

	return x;
}

int main() {

	// TreeNode *root = new TreeNode(8);
	// root->left = new TreeNode(4);
	// root->right = new TreeNode(13);
	// root->left->left = new TreeNode(1);
	// root->left->right = new TreeNode(7);
	// root->left->right->left = new TreeNode(6);
	// root->right->left = new TreeNode(10);
	// root->right->right = new TreeNode(5);
	// root->right->right->right = new TreeNode(17);


	vector<int>v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	TreeNode *root = solve(v, 0, v.size() - 1);

	//print tree
	print(root);


	return 0;
}