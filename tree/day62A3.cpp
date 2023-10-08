#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>>solve(TreeNode *A) {


	vector<vector<int>>ans;
	queue<TreeNode*>q;
	q.push(A);
	q.push(NULL);
	vector<int>v;

	while (q.size() > 1) {
		TreeNode *temp = q.front();

		if (temp == NULL) {
			q.pop();
			q.push(NULL);
			ans.push_back(v);
			v = {};
		} else {
			v.push_back(temp->val);
			if (temp->left != NULL) {
				q.push(temp->left);

			}
			if (temp->right != NULL) {
				q.push(temp->right);
			}
			q.pop();
		}
	}
	if (v.size() != 0) {
		ans.push_back(v);
	}

	return ans;
}


int main() {

	TreeNode  *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left =  new TreeNode(15);
	root->right->right = new TreeNode(7);


	// TRAVERSE THE TREE using Inorder Traversal
	// cout << "\nTraversing  : ";
	// print(root);
	// cout << "\n\n";


	// Level order traversal
	vector<vector<int>> ans;

	ans = solve(root);

	for (auto q : ans) {
		for (auto w : q) {
			cout << w << " ";
		}
		cout << "\n";
	}

	return 0;
}