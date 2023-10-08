#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool cmp(int a, int b) {

    int x = 0;
    int y = 0;

    while (a) {
        if ((a & 1) == 1) {
            x++;
        }
        a = a >> 1;
    }

    while (b) {
        if ((b & 1) == 1) {
            y++;
        }
        b = b >> 1;
    }

    if (x == y) {
        if (a < b) {
            return true;
        }
        return false;
    } else if (x < y) {
        return true;
    }
    return false;
}

int main() {


    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    sort(v.begin(), v.end(), cmp);

    for (auto q : v) {
        cout << q << " ";
    }

    return 0;

}

