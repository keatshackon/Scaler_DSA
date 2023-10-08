#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}

};
//PRINTING THE TREE
void print(TreeNode*root) {
	if (root == NULL) return;

	queue<TreeNode*>q;
	q.push(root);
	while (!q.empty()) {
		TreeNode*temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
	cout << "\n\n";
}

void helper1(TreeNode *root, TreeNode *k) {

	TreeNode *pre = NULL;

	while (root != NULL) {
		pre = root;
		if (root->val > k->val) {
			root = root->left;
		} else {
			root = root->right;
		}
	}
}

void helper2(TreeNode *root) {

}

void solve(TreeNode *root, int k) {

	if (root == NULL) {
		return;
	}

	map<int, TreeNode*>m;

	// First, Search Node;
	queue<TreeNode*>q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();
		m[temp->val] = temp;
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}

	for (auto q : m) {
		cout << q.first << "  " << q.second << "\n";
	}
	cout << "\n";

	if (m.count(k) != 0) {
		TreeNode *temp = m[k];
		if (temp->left == NULL or temp->right == NULL) {
			helper(root);
		} else {

		}
	} else {
		cout << "Element isn't there\n";
	}
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

	//Before Deletion
	print(root);

	int k = 17;
	solve(root, k);


	//After Deletion of leaf node
	print(root);


	return 0;
}