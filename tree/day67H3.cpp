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

void solve(TreeNode *root, int &odd, int &even, int lable) {

	if (root == NULL) {
		return;
	}
	if (lable % 2 == 1) {
		odd += root->val;
	} else {
		even += root->val;
	}
	solve(root->left, odd, even, lable + 1);
	solve(root->right, odd, even, lable + 1);

}

int main() {

	TreeNode  *root = new TreeNode(3);
	root->left = new TreeNode(20);
	root->right = new TreeNode(4);
	root->right->left =  new TreeNode(14);
	root->right->right = new TreeNode(18);
	root->left->left =  new TreeNode(9);
	root->left->left->left =  new TreeNode(2);
	root->left->left->right =  new TreeNode(19);


	// Priting tree to ensure the construction of tree
	cout << "Traversing :";
	print(root);
	cout << "\n\n";

	int odd = 0;
	int even = 0;
	solve(root, odd, even , 1);

	cout << odd << " " << even << "\n";
	cout << (odd - even) << "\n";

	return 0;
}