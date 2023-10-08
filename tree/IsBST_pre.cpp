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

	if (root == NULL) return ;

	queue<TreeNode*>q;
	q.push(root);
	while (!q.empty()) {
		TreeNode * temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
	cout << "\n";
}

// Iteratice
int solve2(TreeNode *root) {

	if (root == NULL) return true;
	stack<TreeNode*> stack;
	TreeNode *pre = NULL;
	while (root != NULL || !stack.empty()) {
		while (root != NULL) {
			stack.push(root);
			root = root->left;
		}
		root = stack.top();
		stack.pop();
		if (pre != NULL && root->val <= pre->val) return false;
		pre = root;
		root = root->right;
	}
	return true;
}


// Re
int solve(TreeNode*root, int a, int d) {

	if (root == NULL) {
		return 1;
	}
	if (!(root->val >= a and root->val <= d)) {
		return 0;
	}

	return solve(root->left, a, root->val - 1) &&
	       solve(root->right, root->val + 1, d);

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

	//print tree
	print(root);

	int ans = solve(root, INT_MIN, INT_MAX);
	if (ans == 1) {
		cout << "BST HAI";
	} else {
		cout << "BST NAHI HAI\n";
	}


	return 0;
}