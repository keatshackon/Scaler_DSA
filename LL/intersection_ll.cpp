#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {

	int data;
	struct Node *next;
	Node(int x): data(x), next(NULL) {}
};

// Map APPROACHES
int solve(Node *head1, Node *head2) {

	unordered_map<Node*, int>m;

	while (head1 != NULL) {
		m[head1]  = 1;
		head1 = head1->next;
	}
	while (head2 != NULL) {
		if (m.count(head2) != 0) {
			return head2->data;
		}
		head2 = head2->next;
	}
	return -1;
}

int main() {


	int cnt1 = 0, cnt2 = 0;

	Node *temp1 = head1;
	Node *temp2 = head2;

	while (temp1 != NULL) {
		cnt1++;
		temp1 = temp1->next;
	}
	while (temp2 != NULL) {
		cnt2++;
		temp2 = temp2->next;
	}


	if (cnt1 > cnt2) {

		int diff = cnt1 - cnt2;
		while (diff) {
			head1 = head1->next;
			diff--;
		}
	} else {
		int diff = cnt2 - cnt1;
		while (diff) {
			head2 = head2->next;
			diff--;
		}
	}

	while (head1 != NULL and head2 != NULL) {

		if (head1 == head2) {
			return head1->data;
		}
		head1 = head1->next;
		head2 = head2->next;
	}

	// return -1;

	return 0;
}