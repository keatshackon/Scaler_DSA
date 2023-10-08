#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {

	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// Printing Tree
void print(TreeNode *root) {

	queue<TreeNode*>q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left != NULL) {
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}
}

int ans = INT_MIN;

int solve(TreeNode *root) {


	if (root == NULL) {
		return 0;
	}
	ans = max(ans, root->val);
	int hl = solve(root->left);
	int hr = solve(root->right);
	int sum = (hl + hr + root->val);

	ans = max(ans, sum);

	return sum;
}


int main() {

	TreeNode *root = new TreeNode(-10);
	root->left = new TreeNode(9);
	// root->right = new TreeNode(20);
	// root->right->left = new TreeNode(15);
	// root->right->right = new TreeNode(7);

	//printing
	print(root);
	cout << "\n\n";

	solve(root);
	cout << ans << "\n";

	return 0;
}