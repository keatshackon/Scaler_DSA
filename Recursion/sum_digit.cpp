#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sum(int k) {

	if (k == 0) {
		return 0;
	}

	int temp = k % 10;
	return temp + sum (k / 10);

}

int main() {

	int k = 234;

	cout << sum(k);

	return 0;
}
