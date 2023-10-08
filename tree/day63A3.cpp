#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {

	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// Testing Tree Construction
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

// TOP VIEW AS WELL AS BOTTOM VIEW OF BINARY TREE
vector<int> solve(TreeNode *root) {

	if (root == NULL) {
		return {};
	}

	queue<pair<int, TreeNode*>>q;
	q.push({0, root});
	vector<int>ans;
	map<int, vector<int>>m;

	int minn = INT_MAX, maxx = INT_MIN;

	while (!q.empty()) {

		int idx = q.front().first;
		TreeNode *temp = q.front().second;
		q.pop();
		minn = min(minn, idx);
		maxx = max(maxx, idx);
		m[idx].push_back(temp->val);

		if (temp->left != NULL) {
			q.push({idx - 1, temp->left});
		}
		if (temp->right != NULL) {
			q.push({idx + 1, temp->right});
		}
	}

	// for (auto q : m) {
	// 	cout << q.first << " ";
	// 	for (auto w : q.second) {
	// 		cout << w << " ";
	// 	}
	// 	cout << "\n";
	// }

	for (int i = minn; i <= maxx; i++) {
		// FOR BOTTOM VIEW
		ans.push_back(m[i][m[i].size() - 1]);

		//FOR TOP VIEW
		ans.push_back(m[i][0]);
	}

	cout << "Top View Of Binary Tree : ";
	for (auto q : ans) {
		cout << q << " ";
	}
	cout << "\n";

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


	// Priting tree to ensure the construction of tree
	cout << "Traversing :";
	print(root);
	cout << "\n\n";

	solve(root);

	return 0;
}