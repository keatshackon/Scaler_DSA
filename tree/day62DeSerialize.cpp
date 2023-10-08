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

TreeNode* solve(vector<int>A) {

	int len = A.size();
	int j = 1;
	TreeNode *root = new TreeNode(A[0]);
	queue<TreeNode*>q;
	q.push(root);

	while (j < len) {
		TreeNode* temp = q.front();
		q.pop();
		if (A[j] != -1) {
			temp->left = new TreeNode(A[j]);
			q.push(temp->left);
		} else {
			temp->left = NULL;
		}
		j++;
		if (A[j] != -1) {
			temp->right = new TreeNode(A[j]);
			q.push(temp->right);
		} else {
			temp->right = NULL;
		}
		j++;
	}


	return root;
}


int main() {


	vector<int>v = {1, 2, 3, 4, 5, -1, -1, -1, -1, -1, -1};
	TreeNode *root = solve(v);

	print(root);
	return 0;
}