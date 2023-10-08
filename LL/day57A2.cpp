#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ListNode {

	int val;
	struct ListNode *next;
	ListNode(int x) {
		val = x;
		next = NULL;
	}
};

ListNode* merge(ListNode *h1, ListNode *h2) {

	ListNode *dummy1 = new ListNode(-101);
	ListNode *ans = dummy1;

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

ListNode* mergeSort(ListNode* A) {

	if (A == NULL or A->next == NULL) {
		return A;
	}

	ListNode *slow = A;
	ListNode* fast = A->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode* res = slow->next;
	slow->next = NULL;


	return merge(mergeSort(A), mergeSort(res));
}

int main() {


	ListNode *A = new ListNode(4);
	A->next = new ListNode(50);
	A->next->next = new ListNode(6);
	A->next->next->next = new ListNode(17);
	A->next->next->next->next = new ListNode(8);


	ListNode* ans = mergeSort(A);

	while (ans != NULL) {
		cout << ans->val << "\n";
		ans = ans->next;
	}


	return 0;
}