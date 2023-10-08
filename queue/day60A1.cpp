#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {


	int A = 4;
	queue<string>q;

	q.push("1");
	q.push("2");

	string ans = "";

	while (A) {

		string temp = q.front();

		A--;
		string t = temp;
		reverse(t.begin(), t.end());
		ans = temp + t;

		if (A == 0) {
			cout << ans << "\n";
			break;
		}

		q.pop();
		q.push(temp + "1");
		q.push(temp + "2");
	}


	return 0;
}