#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main() {


    vector<int>A = {1, 7, 6, 2, 8, 4, 4, 6, 8, 2 };
    vector<int>B = {8, 11, 7, 7, 10, 8, 7, 5, 4, 9 };


    int n = A.size();

    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

    for (int i = 0; i < n; i++) {
        pq1.push({A[i], B[i]});
    }

    int time = 0;
    int ans = 0;

    while (pq1.size()) {


        pair<int, int> cur = pq1.top();

        if (time <= cur.first - 1) {
            ans = (ans % MOD +  cur.second % MOD) % MOD;
            time++;
            pq2.push({pq1.top().second, pq1.top().first});
            pq1.pop();
        } else if ( !pq2.empty() and pq2.top().first <= pq1.top().second) {
            ans -= pq2.top().first;
            ans = (ans % MOD +  cur.second % MOD) % MOD;
            pq2.pop();
            pq2.push({pq1.top().second, pq1.top().first});
            pq1.pop();
        } else {
            pq1.pop();
        }

    }

    cout << ans << "\n";

    return 0;
}