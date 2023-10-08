#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


int solve(ListNode *head) {


	if (head->next == NULL) return 1;

	ListNode *slow = head, *fast = head;


	while (fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	cout << slow->val << "\n";


	ListNode *res = slow->next;


	ListNode *start2 = res;
	ListNode *temp = res->next, *temp2 = res->next;

	start2->next = NULL;

	while (temp2 != NULL) {
		temp2 = temp2->next;
		temp->next = start2;
		start2 = temp;
		temp = temp2;
	}


	while (start2 != NULL ) {
		if (start2->val != head->val) {
			return 0;
		}
		start2 = start2->next;
		head = head->next;
	}

	return 1;

}

int main() {


	ListNode *head = new ListNode(1);
	head->next = new ListNode(1);
	// head->next->next = new ListNode(1);
	// head->next->next->next = new ListNode(2);
	// head->next->next->next->next = new ListNode(1);


	cout << solve(head);



	return 0;
}