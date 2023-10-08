#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {



	ListNode *ans = NULL;
	ListNode *res = NULL;

	while (head1 != NULL and head2 != NULL) {

		if (head1->val < head2->val) {

			if (ans == NULL) {
				ans = head1;
				res = ans;
				head1 = head1->next;
				ans->next = NULL;
			} else {
				ans->next = head1;
				ans = head1;
				head1 = head1->next;
				ans->next = NULL;
			}

		} else {
			if (ans == NULL) {
				ans = head2;
				res = ans;
				head2 = head2->next;
				ans->next = NULL;
			} else {
				ans->next = head2;
				ans = head2;
				head2 = head2->next;
				ans->next = NULL;
			}
		}
	}

	while (head1 != NULL) {
		if (ans == NULL) {
			ans = head1;
			res = ans;
			head1 = head1->next;
			ans->next = NULL;
		} else {
			ans->next = head1;
			head1 = head1->next;
			ans = ans->next;
			ans->next = NULL;
		}
	}

	while (head2 != NULL) {
		if (ans == NULL) {
			ans = head2;
			res = ans;
			head2 = head2->next;
			ans->next = NULL;
		} else {
			ans->next = head2;
			head2 = head2->next;
			ans = ans->next;
			ans->next = NULL;
		}
	}

	return 0;
}