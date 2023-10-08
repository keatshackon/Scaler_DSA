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


ListNode* solve(ListNode *head) {

	if (head == NULL or head->next == NULL) return head;


	ListNode *temp = head,
	          *ans = head->next,
	           *temp2 = head->next;

	temp->next = NULL;

	while (temp2 != NULL) {
		temp2 = temp2->next;
		ans->next = temp;
		temp = ans;
		ans = temp2;
	}

	return temp;
}


int main() {


	ListNode *head = new ListNode(4);
	head->next = new ListNode(5);
	head->next->next = new ListNode(6);
	head->next->next->next = new ListNode(7);
	head->next->next->next->next = new ListNode(8);
	head->next->next->next->next->next = new ListNode(9);


	cout << "Before : ";
	print_ll(head);

	//solve(head);

	cout << "\nAfter : ";
	head = solve(head);
	print_ll(head);

	return 0;
}