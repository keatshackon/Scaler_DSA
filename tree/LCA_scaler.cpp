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

bool solve(TreeNode *root, int k, vector<int> &path) {

	if (root == NULL) {
		return false;
	}

	path.push_back(root->val);
	if (root->val == k) {
		return true;
	}

	bool h1 = solve(root->left, k, path);
	bool h2 = solve(root->right, k, path);

	if (h1 or h2) {
		return true;
	}

	if (h1 == false and h2 == false) {
		path.pop_back();
		return false;
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

	vector<int>path_a;
	vector<int>path_b;

	//Finding The path of 16 from root
	solve(root, 16, path_a);

	for (auto q : path_a) {
		cout << q << " ";
	}
	cout << "\n";

	//Finding The Path of 22 from root
	solve(root, 22, path_b);

	for (auto q : path_b) {
		cout << q << " ";
	}
	cout << "\n";


	//Finding The

	int i = 0;
	int ans = 0;
	while (i < path_b.size() and i < path_a.size()) {
		if (path_b[i] == path_a[i]) {
			ans = path_a[i];
		} else {
			break;
		}
		i++;
	}

	cout << "LCA Of The " << 16 << " And " << 22 << " Is : " << ans << "\n";

	return 0;
}