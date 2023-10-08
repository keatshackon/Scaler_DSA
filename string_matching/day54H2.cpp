#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {



	sting A =  "adaddb";


	int i = 0;
	int j = 0;
	int cnt = 0;
	while (i < j) {
		if (A[i] != A[j]) {
			cnt++;
		}
	}


	if (cnt > 1) {
		cout << "NO";
	} else {
		cout << "YES";
	}
	return 0;
}