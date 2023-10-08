#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {

	int val;
	TreeNode* left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}

};

void print(TreeNode *root) {

	queue<TreeNode*>q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* temp = q.front();
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




vector<vector<int>> solve(TreeNode* root) {

	vector<vector<int>>ans;


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
	cout << "Level Order Traveral : ";
	print(root);
	cout << "\n\n";



	return 0;
}