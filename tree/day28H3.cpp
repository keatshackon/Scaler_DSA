#include <bits/stdc++.h>
using namespace std;
#define ll long long


int Solution::solve(TreeNode* A) {

    if (A ==  NULL) {
        return 0;
    }

    int h1 = solve(A -> left);
    int h2 = solve(A -> right);

    return 1 + h1 + h2;
}

int main() {

}