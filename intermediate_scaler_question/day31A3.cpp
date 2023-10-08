#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> solve(int A, vector<vector<int> > &B) {

    vector<int>v(A);
    vector<int>v1(A);

    for (int i = 0; i < B.size(); i++) {
        v[B[i][0] - 1] += B[i][2];
    }

    for (auto q : v) {
        cout << q << " ";
    }
    cout << "\n";

    for (int i = 1; i < v.size(); i++) {
        v[i] = v[i - 1] + v[i];
    }

    for (auto q : v) {
        cout << q << " ";
    }
    cout << "\n";

    for (int i = 0; i < B.size(); i++) {
        if (B[i][1] < v1.size()) {
            v1[B[i][1]] -= B[i][2];
        }

    }

    for (auto q : v1) {
        cout << q << " ";
    }
    cout << "\n";


    for (int i = 1; i < v1.size(); i++) {
        v1[i] = v1[i - 1] + v1[i];
    }

    for (auto q : v1) {
        cout << q << " ";
    }
    cout << "\n";

    for (int i = 0; i < v1.size(); i++) {
        v[i] = v1[i] + v[i];
    }

    for (auto q : v) {
        cout << q << " ";
    }
    cout << "\n";
    return v;
}

int main() {

    vector<vector<int>> v  = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};

    vector<int>ans = solve(5, v);

    for (auto q : ans) {
        cout << q << " ";
    }


    return 0;
}
