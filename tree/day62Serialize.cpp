#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {

	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *root) {

	queue<TreeNode*>q;
	q.push(root);

	while (!q.empty()) {
		TreeNode *temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left != NULL) {
			q.push(temp->left);
		}
		if (temp->right) {
			q.push(temp->right);
		}
	}
}

vector<int> solve(TreeNode* A) {


	queue<TreeNode*>q;
	q.push(A);
	vector<int>ans;
	ans.push_back(A->val);

	while (!q.empty()) {
		TreeNode *temp = q.front();
		q.pop();
		if (temp ->left != NULL) {
			q.push(temp->left);
			ans.push_back(temp->left->val);
		} else {
			ans.push_back(-1);
		}

		if (temp ->right != NULL) {
			q.push(temp->right);
			ans.push_back(temp->right->val);
		} else {
			ans.push_back(-1);
		}
	}

	return ans;
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

	// checking purpose
	print(root);
	cout << "\n\n";



	vector<int>v = solve(root);

	for (auto q : v) {
		cout << q << " ";
	}


	return 0;
}