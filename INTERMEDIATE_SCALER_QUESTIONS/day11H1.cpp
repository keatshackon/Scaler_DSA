#include<bits/stdc++.h>
using namespace std;

const int MOD = 10003;
bool isVowel(char A) {
	bool res = true;
	switch (A) {
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'i':
	case 'I':
	case 'o':
	case 'O':
	case 'u':
	case 'U':
		res = true;
		break;
	default:
		res = false;
		break;
	}
	return res;
}

int main() {

	string A = "aaa";
	int count = 0;
	size_t N = A.length();
	for (size_t i = 0; i < N; i++) {
		if (isVowel(A[i])) {
			count = (count % MOD + (N - i) % MOD) % MOD;
		}
	}
	cout << count;
}



