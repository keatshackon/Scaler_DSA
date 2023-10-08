#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> topoSort(int n, vector<int>g[]) {

	vector<int>indegree(n, 0);

	for (int i = 0; i < n; i++) {
		for (auto q : g[i]) {
			indegree[q]++;
		}
	}

	// CAN USE PRIORITY QUEUE IF WE WANT LEXOGRAPHICAL ORDER.
	queue<int>q;
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int>ans;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		ans.push_back(temp);

		for (auto it : g[temp]) {
			indegree[it]--;
			if (indegree[it] == 0) {
				q.push(it);
			}
		}
	}

	return ans;
}


int main() {

	//cin >> n;

	vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
	int N = dict.size();

	int K = 4;


	vector<int>g[K];

	for (int i = 0; i < N - 1 ; i++) {
		string s1 = dict[i];
		string s2 = dict[i + 1];

		cout << s1 << " " << s2 << "\n";

		int len = min(s1.length(), s2.length());

		for (int k = 0; k < len; k++) {
			if (s1[k] != s2[k]) {
				g[s1[k] - 'a'].push_back(s2[k] - 'a');
				break;
			}
		}
	}

	for (int i = 0; i < K; i++) {
		cout << i << " : ";
		for (auto w : g[i]) {
			cout << w << " ";
		}
		cout << "\n";
	}

	vector<int>res = topoSort(K, g);
	string ans = "";

	for (auto q : res) {
		cout << q << " ";
		ans += char(q + 'a');
	}

	cout << ans << "\n";

	return 0;
}
