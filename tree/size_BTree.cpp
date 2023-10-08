#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int size(TreeNode *root) {

	if (root == NULL) return 0;

	int h1 = size(root->left);
	int h2 = size(root->right);

	return (1 + h1 + h2);

}


int main() {

	TreeNode  *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left =  new TreeNode(15);
	root->right->right = new TreeNode(7);

	int siz = size(root);

	cout << "Size Of Binary Tree : " << siz << "\n";


	return 0;
}
