#include <bits/stdc++.h>
using namespace std;
#define ll long long



int dfs(int n, int parent, vector<int>g[], vector<int>&vis) {

    vis[n] = 1;
    for (auto q : g[n]) {
        if (!vis[q]) {
            return dfs(q, n, g, vis);
        } else if (q != parent) {
            return 0;
        }
    }
    return 1;
}


int main() {

    int A = 2;
    vector<vector<int>>B = { {1, 2},
    };


    vector<int>g[A + 1];
    int len = B.size();

    for (int i = 0; i < len; i++) {
        g[B[i][0]].push_back(B[i][1]);
        g[B[i][1]].push_back(B[i][0]);
    }

    for (int i = 1; i <= A; i++) {
        cout << i << ": ";
        for (auto q : g[i]) {
            cout << q << " ";
        }
        cout << "\n";
    }

    vector<int>vis(A + 1, 0);

    for (int i = 1; i <= A; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, g, vis) == 0) {
                cout << "true";
                return true;
            }
        }
    }

    cout << "False";

    return false;

    return 0;
}
