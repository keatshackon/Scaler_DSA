#include <bits/stdc++.h>
using namespace std;
#define ll long long

ListNode* merge(ListNode *h1, ListNode *h2) {

	ListNode *dummy1 = new ListNode(-101);
	ListNode *temp1 = dummy1;

	if (h1 == NULL) {
		return h2;
	} else if (h2 == NULL) {
		return h1;
	}

	while (h1 != NULL and h2 != NULL) {

		if (h1->val < h2->val) {
			ans->next = h1;
			ans = h1;
			h1 = h1->next;
			ans->next = NULL;
		} else {
			ans->next = h2;
			ans = h2;
			h2 = h2->next;
			ans->next = NULL;
		}
	}
	while (h1 != NULL) {
		ans->next = h1;
		ans = h1;
		h1 = h1->next;
		ans->next = NULL;
	}
	while (h2 != NULL) {
		ans->next = h2;
		ans = h2;
		h2 = h2->next;
		ans->next = NULL;
	}

	return dummy1->next;
}

int main() {

	ListNode *head = new ListNode(4);
	head->next = new ListNode(5);
	head->next->next = new ListNode(6);
	head->next->next->next = new ListNode(7);
	head->next->next->next->next = new ListNode(8);

	//merge(h1, h2);

	return 0;
}