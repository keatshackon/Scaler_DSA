#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), right(NULL), left(NULL) {}
};

// Printing The Tree
void print(TreeNode *root) {

	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}


// Wrong Answer for 5 and 8 Need to check
int solve(TreeNode *root, int k, int l) {

	if (root == NULL) {
		return -1;
	}

	int h1 = solve(root->left, k, l);
	int h2 = solve(root->right, k, l);

	if (root->val == k) {
		return k;
	} else if (root->val == l) {
		return l;
	}

	if (h1 == -1 and h2 == -1) {
		return -1;
	} else if (h1 != -1 and h2 != -1) {
		return root->val;
	} else if (h2 != -1) {
		return h2;
	}
}

int main() {

	TreeNode *root = new TreeNode(15);
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


	// Checking Construction Of Tree
	print(root);
	cout << "\n\n";

	int ans = solve(root, 5, 8);
	cout << ans << "\n";
	return 0;
}