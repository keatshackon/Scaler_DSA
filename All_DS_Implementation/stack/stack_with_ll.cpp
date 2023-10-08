#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {

	int val;
	struct Node *next;
	Node() {
		val = -1;
		next = NULL;
	}
};
struct Node *head = NULL;

void print() {
	struct Node *temp = head;
	while (temp != NULL) {
		cout << (temp->val) << " ";
		temp = temp -> next;
	}
	cout << "\n";
}

int top() {
	if (head != NULL) {
		return head->val;
	}
}

void pop() {
	struct Node *res = head;
	if (head != NULL) {
		res = head->next;
		free(head);
		head = res;
	}
}

void push(int val) {
	struct Node *n = (Node*) malloc(sizeof(struct Node));
	n->val = val;
	if (head == NULL) {
		head = n;
		head->next = NULL;
	} else {
		n->next = head;
		head = n;
	}
}

int main() {

	vector<vector<int>>q = {{1, 2}, {1, 22}, {1, 23}, {3}, {2}, {2}, {1, 40}, {3}, {4}};
	for (int i = 0; i < q.size(); i++) {
		if (q[i][0] == 1) {
			push(q[i][1]);
		} else if (q[i][0] == 2) {
			pop();
		} else if (q[i][0] == 3) {
			print();
		} else {
			cout << top();
		}
	}
	return 0;
}