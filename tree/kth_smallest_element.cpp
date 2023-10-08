#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// Printing Tree
void print(TreeNode* root) {

	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}

// USING EXTRA SPACE METHOD 1
void solve1(TreeNode *root, vector<int>&v) {

	if (root == NULL) {
		return;
	}
	solve1(root->left, v);
	v.push_back(root->val);
	solve1(root->right, v);
}

// WITHOUT EXTRA SPACE METHOD 2
int solve2(TreeNode *root, int k, int &cnt, int &ans) {

	if (root == NULL) {
		return 0;
	}
	int h1 = solve2(root->left, k, cnt, ans);
	if (h1 == -1) {
		return -1;
	}
	cnt++;
	cout << cnt << "\n";
	if (cnt == k) {
		ans = root->val;
		return -1;
	}
	int h2 = solve2(root->right, k, cnt, ans);
	if (h2 == -1) {
		return -1;
	}
}

int main() {

	TreeNode *root = new TreeNode(15);
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

	//Checking Construction Of Tree
	print(root);
	cout << "\n\n";

	// Finding the k th smallest using vector and Inorder
	// vector<int>ans;
	int k = 3;
	// solve1(root, ans);

	// cout << "The Kth Smallest element is : " << ans[k - 1] << "\n";


	//Method 2
	int cnt = 0;
	int ans = -1;
	solve2(root, k, cnt, ans);
	cout << ans;
	return 0;
}