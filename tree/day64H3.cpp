#include <bits/stdc++.h>
using namespace std;
#define ll long long

class BstIterator {

private:
	stack<TreeNode*>st;
	int reverse = false;

public:

	BstIterator(TreeNode *root, bool rev) {
		reverse = rev;
		push_all(root);
	}

	int Next(TreeNode *cur) {
		if (!st.empty()) {
			TreeNode *temp = st.top();
			st.pop();
			if (rev == 1) {
				push_all(cur->right);
			} else {
				push_all(cur->left);
			}

			return temp->val;
		}
		return 0;// will not reach here.
	}


	bool hasNext() {
		return !st.empty();
	}


	void push_all(TreeNode *cur) {
		while (cur != NULL) {
			st.push(cur);
			if (rev)
				cur = cur->left;
			else
				cur = cur->right;
		}
	}
};


int main() {


	BstIterator l(root, 1);
	BstIterator r(root, 0);

	while (l < r) {
		int temp = l.Next() + r.Next();

		if (temp == target) {
			cout << "yes";
			return true;
		} else if (temp < target) {
			l = l.Next();
		} else {
			r = r.Next();
		}
	}


	return 0;
}