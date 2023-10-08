#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {

	int A = 1; // 1011101
	int B = 1;

	int k = 0;
	int temp = 1;
	while (k < B) {

		if ((A & temp) >= 1) {
			A = A ^ temp;
		}
		temp = temp << 1;
		cout << temp << '\n';
		k++;
		//	cout << A << "\n";
	}
	cout << A;
	return 0;

}