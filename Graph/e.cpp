#include <bits/stdc++.h>
using namespace std;
#define ll long long


int dfs(int c, int b, map<int, vector<int>>&m, vector<int>&visited) {

    //visited[c]  = 1;

    if (m.count(c) == 0) {
        return 0;
    }

    for (auto q : m[c]) {
        if (q == b) {
            return 1;
        }
        if (dfs(q, b, m, visited)) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {

    vector<int> A = {1, 1, 2};
    int b = 3;
    int c = 2;

    int len = A.size();

    map<int, vector<int>>m;
    vector<int>visited(len + 1, 0);

    for (int i = 1; i < len; i++) {
        m[A[i]].push_back(i + 1);
    }

    for (auto q : m) {
        cout << q.first << ": ";
        for (auto w : q.second) {
            cout << w << " ";
        }
        cout << "\n";
    }

    for (auto w : m[c]) {
        if (c == m[b]) {
            return 1;
        }
        if (dfs(w, b, m, visited)) {
            cout << "1";
            return 0;
        }
    }

    cout << "0";
    return 0;
}



















