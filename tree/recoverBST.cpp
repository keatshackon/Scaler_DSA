#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//Printing Tree Using Inorder
void print(TreeNode *root) {

	if (root == NULL) {
		return;
	}
	print(root->left);
	cout << root->val << " ";
	print(root->right);

}


// void solve(TreeNode *root, vector<int> &v) {

// 	if (root == NULL) {
// 		return;
// 	}
// 	solve(root->left, v);
// 	v.push_back(root->val);
// 	solve(root->right, v);

// }

TreeNode* solve2(TreeNode *root, TreeNode *prev, int &first, int &second) {

	if (root == NULL) {
		return NULL ;
	}
	TreeNode* h1 = solve(root->left, prev, first, second);

	if (h1 != NULL and prev == NULL) {
		prev = root;
	} else if (h1 != NULL) {
		if (prev->val > root->val and first == -1) {
			first = prev->val;
			second = root->val;
		} else if (prev->val < second) {
			second = prev->val;
		}
		prev = h1;
	}
	solve2(root->right, prev, first, second);

	return prev;

}

int main() {

	TreeNode  *root = new TreeNode(15);
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
	cout << "\n";

	vector<int>ans;

	// without Extra Space
	TreeNode *prev = NULL;
	int first = -1;
	int second = -1;
	solve2(root, prev, first, second);

	// using extra space to find the culprit
//	solve(root, ans);
	// int idx1 = - 1;
	// int idx2 = -1;

	// for (int i = 1; i < ans.size(); i++) {
	// 	if ((ans[i] < ans[i - 1]) and idx1 == -1) {
	// 		idx1 = ans[i - 1];
	// 		idx2 = ans[i];
	// 	} else if ((ans[i] < idx2) and idx1 != -1) {
	// 		idx2 = ans[i];
	// 	}
	// }

	// cout << idx1 << " " << idx2 << "\n";

	return 0;
}