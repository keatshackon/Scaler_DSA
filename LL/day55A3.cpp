#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct ListNode {

	int val;
	ListNode *next;
	ListNode(int x) {
		val = x;
		next = NULL;
	}
};

void print_ll(ListNode *head) {

	ListNode *temp = head;

	while (temp != NULL) {
		cout << temp -> val << " ";
		temp = temp -> next;
	}
}


void solve(ListNode *head) {


	ListNode *slow = head, *fast = head;
	while (fast->next != NULL  && fast -> next -> next != NULL) {
		slow = slow->next, fast = fast->next->next;
	}

	if (fast->next == NULL) {
		cout << slow -> val;
		return;
	}
	cout << slow ->next->val;

}


int main() {


	ListNode *head = new ListNode(4);
	head->next = new ListNode(5);
	head->next->next = new ListNode(6);
	head->next->next->next = new ListNode(7);
	head->next->next->next->next = new ListNode(8);
	// head->next->next->next->next->next = new ListNode(9);


	solve(head);

	print_ll(head);

	return 0;
}