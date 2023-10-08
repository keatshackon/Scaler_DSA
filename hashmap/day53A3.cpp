#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {


	string A = "Aa91b";
	string B = "ab";

	map<char, int> map2;

	for (int i = 0; i < B.length(); i++) {
		map2[B[i]]++;
	}

	int track = map2.size();

	int n = A.length();
	int ans = INT_MAX;

	int x = -1;
	int y = -1;

	int i = 0;
	int j = 0;

	while (j < n) {

		if (track != 0) {
			if (map2.count(A[j]) != 0) {
				map2[A[j]]--;
				if (map2[A[j]] == 0) {
					track--;
				}
			}

			while (track == 0 and i < n) {
				if (map2.count(A[i]) != 0) {
					map2[A[i]]++;
					if (map2[A[i]] > 0) {
						track++;
					}
				}
				if (ans > (j - i + 1)) {
					x = i;
					y = j;
					ans = j - i + 1;
				}
				i++;
			}
		} else {
			while (track == 0 and i < n) {
				if (map2.count(A[i]) != 0) {
					map2[A[i]]++;
					if (map2[A[i]] > 0) {
						track++;
					}
				}
				if (ans > (j - i + 1)) {
					x = i;
					y = j;
					ans = j - i + 1;
				}
				i++;
			}
		}
		j++;
	}

	cout << ans << "\n";

	string res = "";

	if (x  != -1) {
		while (x <= y) {
			res += A[x];
			x++;
		}
	} else {
		// return "";
		cout << "NO\n";
	}

	cout << res;


	return 0;
}

