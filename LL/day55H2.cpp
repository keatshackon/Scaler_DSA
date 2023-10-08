#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);


	// if (head == NULL or head->next == NULL) {
	// 	return  head;
	// }

	ListNode *temp = head;

	while (temp != NULL) {

		if (temp->next == NULL) {
			return head;
		} else if (temp->val == temp->next->val) {
			temp->next = temp->next->next;
		} else {
			temp = temp->next;
		}
	}

	// return head;
	return 0;
}