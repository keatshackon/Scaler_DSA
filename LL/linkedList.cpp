#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct ListNode {

	int val;
	struct ListNode *next;
	linkedList(int x) {
		val = x;
		next = NULL;
	}

};


bool search(ListNode *head, int k) {

	ListNode *temp = head;

	while (temp != NULL) {
		if (temp -> val == k) {
			return true;
		}
	}
	return false;
}

void printll(ListNode *head) {

	ListNode *temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}


int main() {


	ListNode *head = new ListNode(4);
	head->next = new ListNode(5);
	head->next->next = new ListNode(6);
	head->next->next->next = new ListNode(7);
	head->next->next->next->next = new ListNode(8);



	printll(head);


	return 0;
}