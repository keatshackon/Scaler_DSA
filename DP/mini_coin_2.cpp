#include <bits/stdc++.h>
using namespace std;
#define ll long long


long long solve(int n, vector<int>&coin, int amount) {
    if (amount == 0ll) {
        return 0ll;
    } else if (amount < 0) {
        return LLONG_MAX - 100000;
    }
    if (n == -1ll) {
        return LLONG_MAX - 100000;
    }

    if (amount >= coin[n]) {
        return min(1ll + solve(n, coin, amount - coin[n]), solve(n - 1, coin, amount));
    } else {
        return solve(n - 1, coin, amount);
    }
}


int main() {

    vector<int>coins = {411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422};

    int len = coins.size();
    int amount = 9864;
    long long ans = solve(len - 1, coins, amount);
    if (ans > INT_MAX or ans < INT_MIN) {
        cout << - 1;
        return 0;
    }
    cout << ans;

    return 0;
}