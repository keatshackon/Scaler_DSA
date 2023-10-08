#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct linkedList {

	int val;
	struct linkedList *next;
	linkedList(int x) {
		val = x;
		*next = NULL;
	}

};

void printll(linkedList *head) {

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
}


int main() {


	linkedList *head = new linkedList(4);
	head->next = new linkedList(5);
	head->next->next = new linkedList(6);
	head->next->next->next = new linkedList(7);
	head->next->next->next->next = new linkedList(8);






	return 0;
}