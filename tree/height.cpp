#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

int height(TreeNode *root) {

	if (root == NULL) return -1;

	int h1 = height(root->left);
	int h2 = height(root->right);

	return 1 + max(h1, h2);

}


int main() {

	TreeNode  *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left =  new TreeNode(15);
	root->right->right = new TreeNode(7);

	int h = height(root);

	cout << "Height Of Tree : " << h << "\n";


	return 0;
}
