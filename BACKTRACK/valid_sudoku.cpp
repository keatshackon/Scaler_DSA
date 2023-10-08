#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve(vector<vector<char>>& A) {


    // HashSet<Character> hashSet = new HashSet<>();
    set<char> hashSet;

    for (int i = 0; i < 9; i++) {
        hashSet.clear();
        for (int j = 0; j < 9; j++) {
            char c = A[i][j];
            if (c == '.')
                continue;
            if (hashSet.find(c) != hashSet.end())
                return 0;
            hashSet.insert(c);
        }
    }

    for (int i = 0; i < 9; i++) {
        hashSet.clear();
        for (int j = 0; j < 9; j++) {
            char c = A[j][i];
            if (c == '.')
                continue;
            if (hashSet.find(c) != hashSet.end())
                return 0;
            hashSet.insert(c);
        }
    }


    for (int k = 0; k < 9; k++) {
        int x = k / 3;
        int y = k % 3;
        hashSet.clear();
        for (int i = 3 * x; i < 3 * x + 3; i++) {
            for (int j = y * 3; j < y * 3 + 3; j++) {
                char c = A[j][i];
                if (c == '.')
                    continue;
                if (hashSet.find(c) != hashSet.end())
                    return 0;
                hashSet.insert(c);
            }
        }

    }
    return 1;
}

int main() {


    vector<vector<char>>board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
        , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
        , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
        , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
        , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
        , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
        , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
        , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
        , {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };



    cout << solve(board);


    // bool r[9][9], c[9][9], s[3][3][9];
    // memset(r, false, sizeof(r));
    // memset(c, false, sizeof(c));
    // memset(s, false, sizeof(s));
    // int number;
    // for (int i = 0; i < 9; i++) {
    //     for (int j = 0; j < 9; j++) {
    //         if (board[i][j] > '0' && board[i][j] <= '9') {
    //             number = board[i][j] - '1';
    //             if (r[i][number]) return false;
    //             r[i][number] = true;
    //             if (c[j][number]) return false;
    //             c[j][number] = true;
    //             if (s[i / 3][j / 3][number]) return false;
    //             s[i / 3][j / 3][number] = true;
    //         }
    //     }
    // }

    // cout << "true";

    return 0;
}
