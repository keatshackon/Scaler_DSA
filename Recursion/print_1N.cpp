#include <bits/stdc++.h>
using namespace std;
#define ll long long


void print(int n) {

	if (n  == 11) {
		return;
	}
	cout << n << " ";
	return print(n + 1);

}


int main() {

	int k = 1;

	print(k);

	return 0;
}