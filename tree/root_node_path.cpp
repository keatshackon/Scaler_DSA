#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {

	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// testing tree construction
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

bool solve(TreeNode *root, vector<int> &v, int node) {

	if (root == NULL) {
		return false;
	}
	if (root->val == node) {
		v.push_back(root->val);
		return true;
	} else {
		v.push_back(root->val);
	}
	bool s1 =  solve(root->left, v, node);
	if (s1 == true) {
		return true;
	}
	bool s2 =  solve(root->right, v, node);
	if (s2 == true) {
		return true;
	}
	if (s1 == false and s2 == false) {
		v.pop_back();
		return false;
	} else {
		return true;
	}
}

int main() {

	TreeNode  *root = new TreeNode(3);
	root->left = new TreeNode(7);
	root->right = new TreeNode(4);
	root->right->left =  new TreeNode(14);
	root->right->right = new TreeNode(18);
	root->left->left =  new TreeNode(9);
	root->left->left->left =  new TreeNode(12);
	root->left->left->right =  new TreeNode(19);


	// priting tree
	cout << "Traversing :";
	print(root);
	cout << "\n\n";

	vector<int>ans;

	solve(root, ans, 3);

	cout << "Path From root to given Node : ";

	for (auto q : ans) {
		cout << q << " ";
	}

	return 0;
}