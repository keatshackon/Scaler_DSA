#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

//Printing The Tree
void print(TreeNode *root) {

	if (root == NULL) return;

	queue<TreeNode*>q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *temp = q.front();
		q.pop();
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
}

// WITH SC O(N) TC O(N)
// void solve(TreeNode* root, vector<int>v) {

// 	if (root == NULL) {
// 		return;
// 	}

// 	solve(root->left, v);
// 	v.push_back(root->val);
// 	solve(root->right, v);
// }

// WITH SC O(1) TC O(N)
bool solve2(TreeNode* root, int &pre) {

	if (root == NULL) {
		return 1;
	}

	return solve2(root->left, pre);
	if (pre == -1) {
		pre = root->val;
	} else {
		if (root->val < pre) {
			return 0;
		} else {
			pre = root->val;
		}
	}

	return solve2(root->right, pre);
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


	int pre = -1;

	int ans = solve2(root, pre);

	if (ans == 1) {
		cout << "BST HAI\n";
	} else {
		cout << "NAHi HAI\n";
	}



	// vector<int>ans;

	// solve(root, ans);
	// int f = 1;
	// for (int i = 1; i < ans.size(); i++) {
	// 	if (ans[i] < ans[i - 1]) {
	// 		f = 0;
	// 		cout << "BST NAHI HAI\n";
	// 		break;
	// 	}
	// }
	// for (auto q : ans) {
	// 	cout << q << " ";
	// }
	// cout << "\n";
	// if (f == 1) {
	// 	cout << "BST HAI\n";
	// }

	return 0;
}