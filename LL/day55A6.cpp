#include <bits/stdc++.h>
using namespace std;
#define ll long long


struct LinkedList {

	int val;
	LinkedList *next;
	LinkedList(int x) {
		val = x;
		next = NULL;
	}
};

LinkedList *head = NULL;


void insert_node(int position, int value) {


	LinkedList *new_node = new LinkedList(value);

	if (position == 1) {
		new_node->next = head;
		head = new_node;
		return;
	}

	int k = 1;
	LinkedList *res = head;

	position--;
	while (k < position) {
		k++;
		res = res->next;
	}

	new_node->next = res->next;
	res->next = new_node;

}

void delete_node(int position) {

	if (head == NULL) {
		return;
	}

	if (position == 1) {
		LinkedList *temp = head;
		head = temp->next;
		temp -> next = NULL;
		free(temp);
		return;
	}

	position--;
	int k = 1;
	LinkedList *res = head;


	while (k < position) {
		k++;
		if (res != NULL)
			res = res->next;
	}

	if (res != NULL and res->next != NULL) {
		LinkedList *join = res->next->next;
		res->next = NULL;
		res->next = join;
	}
}


void print_ll() {
	// Output each element followed by a space

	struct Node *temp = root;
	int flag = 0;
	// traverse the entire linked list
	while (temp != NULL) {
		if (flag == 0) {
			cout << temp -> data;
			flag = 1;
		} else
			cout << " " << temp -> data;
		temp = temp -> next;
	}
}

int main() {


	int t;
	cin >> t;


	while (t--) {
		char c;
		int x, y;
		cin >> c;

		if (c == 'i') {
			cin >> x >> y;
			insert_node(x, y);
		} else if (c == 'd') {
			cin >> x;
			delete_node(x);
		} else if (c == 'p') {
			print_ll();
		}
	}


	return 0;
}