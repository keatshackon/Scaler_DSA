#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct ListNode {

	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

int main() {


	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(1);
	head->next->next->next->next = new ListNode(3);

	int B = 2;
	int res = B;

	ListNode * temp = head;


	ListNode *dummy1 = new ListNode(-101), *dummy2 = new ListNode(-101);

	ListNode* s1 = dummy1, *s2 = dummy2;

	temp = head;

	while (temp != NULL) {
		if (temp->val < res) {
			s1->next = temp;
			s1 = temp;
			temp = temp->next;
			s1->next = NULL;
		} else {
			s2->next = temp;
			s2 = temp;
			temp = temp->next;
			s2->next = NULL;
		}
	}

	s1->next = dummy2->next;


	ListNode *print = dummy1->next;


	while (print != NULL) {
		cout << print->val << " ";
		print = print->next;
	}

	return 0;
}