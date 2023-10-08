#include <bits/stdc++.h>
using namespace std;
#define ll long long


class BstIterator {

public:
	stack<TreeNode*>st;
	BSTIterator(TreeNode* root) {
		while (root != NULL) {
			st.push(root);
			root = root->left;
		}
	}

	int next() {
		if (!st.empty()) {
			TreeNode *temp = st.top();
			st.pop();
			TreeNode *cur = temp->right;
			while (cur != NULL) {
				st.push(cur);
				cur = cur->left;
			}
			return temp->val;
		}
		return 0;
	}

	bool hasNext() {
		return !st.empty();
	}
};


int main() {


	// ABOVE CODE IS WORKING FINE JUST LAZY TO CREATE THE TREE.



	return 0;
}