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


// USING LEVEL ORDER TRAVERSAL
vector<int> solve1(TreeNode *root) {

	if (root == NULL) {};

	vector<int>ans;
	ans.push_back(root->val);
	queue<TreeNode*>q;
	q.push(root);
	q.push(NULL);

	while (q.size() > 1) {
		TreeNode *temp = q.front();
		q.pop();
		if (temp == NULL) {
			q.push(NULL);
			ans.push_back(q.front()->val);
		} else {
			if (temp->left != NULL) {
				q.push(temp->left);
			}
			if (temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
	return ans;
}

// USING RECURSION
void solve2(TreeNode *root, vector<int>&v, int lable) {

	if (root == NULL) {
		return;
	}
	if (v.size() < lable) {
		v.push_back(root->val);
	}
	solve2(root->left, v, lable + 1);
	solve2(root->right, v, lable + 1);
}


int main() {

	TreeNode  *root = new TreeNode(3);
	root->left = new TreeNode(7);
	root->right = new TreeNode(4);
	root->right->left =  new TreeNode(14);
	root->right->right = new TreeNode(18);
	// root->left->left =  new TreeNode(9);
	// root->left->left->left =  new TreeNode(12);
	// root->left->left->right =  new TreeNode(19);


	// Priting tree to ensure the construction of tree
	cout << "Traversing :";
	print(root);
	cout << "\n\n";

	// vector<int>ans = solve1(root, ans, 0);

	vector<int>ans;
	solve2(root, ans, 1);

	cout << "The Left View Of Binary tree : ";
	for (auto q : ans) {
		cout << q << " ";
	}
	cout << "\n";

	return 0;
}