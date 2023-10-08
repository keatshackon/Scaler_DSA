#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *root) {

	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->val << " ";
	print(root->right);
}

// priting from node to root
bool solve1(TreeNode *root, int k, vector<int> &v) {

	if (root == NULL) {
		return false;
	}
	if (root->val == k) {
		v.push_back(root->val);
		return true;

	}
	bool h1 = solve1(root->left, k, v);
	if (h1) {
		v.push_back(root->val);
		return true;
	}
	bool h2  = solve1(root->right, k, v);

	if (h2) {
		v.push_back(root->val);
		return true;
	}
	return h1 or h2;
}

// Priting from ROOT to NODE
bool solve2(TreeNode *root, int k, vector<int> &v) {

	if (root == NULL) {
		return false;
	}
	v.push_back(root->val);
	if (root->val == k) {
		return true;
	}
	bool h1 = solve2(root->left, k, v);
	bool h2 = solve2(root->right, k, v);
	if (h1 == true or h2 == true) {
		return true;
	}

	if (h1 == false and h2 == false) {
		v.pop_back();
	}
	return false;
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


	//Checking Tree Construction
	print(root);
	cout << "\n\n";

	vector<int>path;

	solve2(root, 22, path);

	for (auto q : path) {
		cout << q << " ";
	}
	return 0;
}