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

ListNode* solve(ListNode *head, int b, int c) {

	if (head == NULL or head->next == NULL) return head;


	int k = 1;
	ListNode *res = head;



	if (b == 1) {
		ListNode *temp = head, *res1 = head,
		          *ans = res->next,
		           *temp2 = res->next;

		k += 1;
		while (temp2 != NULL and k < c + 1) {
			temp2 = temp2->next;
			ans->next = temp;
			temp = ans;
			ans = temp2;
			k++;
		}

		res->next = temp;
		res1->next = ans;

		return temp;
	}

	while (true) {

		if (k == b - 1) {
			ListNode *temp = res->next, *res1 = res -> next,
			          *ans = res->next->next,
			           *temp2 = res->next->next;

			k += 2;
			while (temp2 != NULL and k < c + 1) {
				temp2 = temp2->next;
				ans->next = temp;
				temp = ans;
				ans = temp2;
				k++;
			}

			res->next = temp;
			res1->next = ans;

			return head;

		} else {
			res = res->next;
		}

		k++;

	}
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


	head = solve(head, 3, 6);



	cout << "\nAfter : ";
	print_ll(head);

	return 0;
}