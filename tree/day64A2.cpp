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

// With Extra Space
void solve1(TreeNode*root, vector<int> &v) {

	if (root == NULL) {
		return;
	}
	solve(root->left, v);
	v.push_back(root->val);
	solve(root->right, v);
}


// Without  Extra Space
void solve2(TreeNode*root, vector<int> &v) {


}

int main() {

	TreeNode *root = new TreeNode(8);
	root->left = new TreeNode(4);
	root->right = new TreeNode(13);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(7);
	root->left->right->left = new TreeNode(6);
	root->right->left = new TreeNode(10);
	root->right->right = new TreeNode(5);
	root->right->right->right = new TreeNode(17);

	//print tree
	print(root);
	cout << "\n\n";


	return 0;
}