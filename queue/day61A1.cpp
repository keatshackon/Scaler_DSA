#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	//string s = "jyhrcwuengcbnuchctluxjgtxqtfvrebveewgasluuwooupcyxwgl";

	string s = "jpxvxivxkkthvpqhhhjuzhkegnzqri";

	string ans = "";

	map<char, int>m;

	queue<char>q;

	int n = s.length();


	for (int i = 0; i < n; i++) {

		m[s[i]]++;
		q.push(s[i]);

		while (!q.empty() and m[q.front()] > 1) {
			q.pop();
		}

		if (!q.empty()) {
			ans += q.front();
		} else {
			ans += '#';
		}
	}

	cout << ans << "\n";

	return 0;
}