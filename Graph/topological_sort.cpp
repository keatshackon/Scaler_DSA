#include <bits/stdc++.h>
using namespace std;
#define ll long long

// USING BFS
vector<int> solve(int n, vector<int>adj[]) {

    vector<int>ind(V, 0);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            ++ind[adj[i][j]];
        }
    }

    queue<int>q;

    for (int i = 0; i < V; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    vector<int>ans;

    while (!q.empty()) {
        cnt++;
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (auto w : adj[temp]) {
            --ind[w];
            if (ind[w] == 0) {
                q.push(w);
            }
        }
    }

    if (cnt == V) {
        return ans;
    }
    return {};
}


// USING DFS
vector<int> solve2(int n, vector<int>adj[]) {


    stack<int>s;

}


int main() {

    int n = 5, m = 6;
    vector<int>g[n + 1];

    g[1].push_back(2);
    g[2].push_back(1);
    g[1].push_back(4);
    g[4].push_back(1);

    g[2].push_back(3);
    g[3].push_back(2);
    g[2].push_back(5);
    g[5].push_back(2);

    g[3].push_back(4);
    g[4].push_back(3);
    g[3].push_back(5);
    g[5].push_back(3);


    solve(n, g);



    return 0;
}