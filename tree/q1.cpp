#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeNode {

	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


void print_tree(TreeNode *root) {

	if (root == NULL) {
		return;
	}
	print_tree(root->left);
	cout << root->val << " ";
	print_tree(root->right);
}

int main() {

	vector<int>A = {20, 15, 21, 19};

	vector<int>ans;
	int n = A.size();

	TreeNode *root = NULL;

	int max_so_far = INT_MIN;

	// To Iterate Over Array to construct the tree.
	for (int i = 0; i < n; i++) {

		//Creating Node to insert into BST.
		TreeNode *cur = new TreeNode(A[i]);

		// finding the correct position to insert cur Node.

		if (root == NULL) {
			root = cur;
			ans.push_back(A[i]);
			max_so_far = A[i];
		} else {
			TreeNode *temp = root, *prev = NULL;

			int temp_sum = 0;

			while (temp != NULL) {
				if (temp->val < A[i]) {
					prev = temp;
					temp = temp->right;
				} else {
					prev = temp;
					temp = temp->left;
				}
				temp_sum += prev->val;
			}

			if (prev->val > A[i]) {
				prev->left = cur;
			} else {
				prev->right = cur;
			}
			temp_sum += A[i];


			max_so_far = max(temp_sum, max_so_far);
			ans.push_back(max_so_far);
		}
	}


	print_tree(root);

	cout << "\n";

	for (auto q : ans) {
		cout << q << " ";
	}


	return 0;
}