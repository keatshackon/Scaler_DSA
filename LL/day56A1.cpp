#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ListNode {

	int val;
	struct ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};


int main() {


	linkedList *head = new linkedList(4);
	head->next = new linkedList(5);
	head->next->next = new linkedList(6);
	head->next->next->next = new linkedList(7);
	head->next->next->next->next = new linkedList(8);

	ListNode *slow = head;
	ListNode *fast = head;


	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			break;
		}
	}

	if (fast == NULL or fast->next == NULL) {
		// return NULL;
		cout << "NULL" << "\n";
	}

	ListNode *temp = head;

	while (true) {

		if (temp == slow) {
			break;
		}
		temp = temp->next;
		slow = slow->next;
	}

	// cout << slow << "\n";



	return 0;
}