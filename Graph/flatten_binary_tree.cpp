#include <bits/stdc++.h>
using namespace std;
#define ll long


struct TreeNode {

	int val;
	TreeNode *right = NULL;
	TreeNode *left = NULL;

	TreeNode(int x): val(x) {}

};


void solve(TreeNode *root, TreeNode *ans) {

	if (root == NULL) {
		return;
	}

	TreeNode *newNode = new TreeNode(root->val);
	if (ans == NULL) {
		ans = newNode;
	} else {
		ans->right = newNode;
		ans = newNode;
	}

	solve(root->left);
	solve(root->right);
}



int main() {

	TreeNode *root = new TreeNode(3);

	TreeNode *ans = NULL;

	solve(root, ans);



	return 0;

}