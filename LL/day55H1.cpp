#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


int main() {


	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	int B = 5;

	ListNode *temp = head, *res = head;


	int cnt = 1, c = B;

	while (B and temp != NULL) {
		temp = temp->next;
		cnt++;
		B--;
	}

	if (B != 0) {
		// return head->next;
		cout << "val" << " ";
		return 0;
	}

	while (temp != NULL and temp->next != NULL) {
		res = res->next;
		temp = temp->next;
		cnt++;
	}

	if (c + 1 == cnt) {
		head = head->next;
	} else {
		res->next = res->next->next;
	}

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}



	return 0;
}