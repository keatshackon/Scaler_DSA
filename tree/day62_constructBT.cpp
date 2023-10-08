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

TreeNode* solve(vector<int>&inorder, vector<int>&preorder,
                int ins, int ine, int prs, int pre, map<int, int>&m) {

	if (prs > pre) {
		return NULL;
	}
	int idx = m[preorder[prs]];
	TreeNode* x  = new TreeNode(preorder[prs]);

	int s = idx - ins;
	x->left = solve(inorder, preorder, ins, idx - 1, prs + 1, prs + s , m);
	x->right = solve(inorder, preorder, idx + 1, ine, prs + s + 1, pre, m);

	return x;
}


int main() {

	vector<int>inorder = {3, 9, 20, 15, 7};
	vector<int>preorder = {9, 3, 15, 20, 7};

	map<int, int> m;
	for (int i = 0; i < inorder.size(); i++) {
		m[inorder[i]] = i;
	}

	for (auto q : m) {
		cout << q.first << " " << q.second << "\n";
	}
	cout << "\n";

	TreeNode *ans = solve(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1, m);

	// checking purpose
	print(ans);
	cout << "\n";

	return 0;
}