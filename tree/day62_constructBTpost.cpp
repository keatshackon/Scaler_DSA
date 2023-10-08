#include <bits/stdc++.h>
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
		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}
}

TreeNode* solve(vector<int>&inorder, vector<int>&postorder, int ins, int ine, int pos, int poe, map<int, int>&m) {

	if (poe < pos) {
		return NULL;
	}

	TreeNode *x = new TreeNode(postorder[poe]);
	int idx = m[postorder[poe]];
	int s = ine - idx;
	x->left = solve(inorder, postorder, ins, idx - 1, pos, poe - s - 1 , m);
	x->right = solve(inorder, postorder, idx + 1, ine, poe - s, poe - 1, m);

	return x;
}

int main() {

	vector<int>inorder = {6, 1, 3, 2};
	vector<int>postorder = {6, 3, 2, 1};

	map<int, int> m;
	int i = 0;
	for (auto q : inorder) {
		m[q] = i++;
	}

	for (auto q : m) {
		cout << q.first << " " << q.second << "\n";
	}

	TreeNode *ans = solve(inorder, postorder, 0, inorder.size() - 1,
	                      0, postorder.size() - 1, m);


	// checking ans
	print(ans);

	return 0;
}
