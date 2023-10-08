#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct ListNode {

	int val, key;
	struct ListNode *next, *prev;
	ListNode(int x, int y): key(x), value(y), next(NULL), prev(NULL) {}
};


int capacity = 5;
int limit = 0;
map<int, pair<int, ListNode*>> m;

ListNode *head = new ListNode(-101);
ListNode *tail = new ListNode(-101);

head->next = tail;
tail->prev = head;

void apppend_tail(ListNode *res) {

	res->next = tail;
	res->prev = tail->prev;
	tail->prev->next = res;
	res->next->prev = res;
}

int get(int key) {

	if (m.count([key]) != 0) {
		return m[key].first;
	} else {
		return -1;
	}
}

void set(int key, int value) {

	ListNode *temp = new ListNode();

	if (limit < capacity) {
		if (m.count(key) == 0) {
			ListNode *new_node = new ListNode(key, value);
			m[key] = {value, new_node};
			apppend_tail(temp);
		} else {
			ListNode *temp = m[key].second;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			m.erase(key);
			apppend_tail(temp);
		}
		limit++;
	} else {
		head->next->next->prev = head;
		head->next = head->next->next;
		apppend_tail(temp);
	}
}

int main() {







	return 0;

}