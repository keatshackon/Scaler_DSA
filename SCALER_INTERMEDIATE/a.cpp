#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()  {


    int arr[4] = {15, 16, 14, 13};

    int *p = arr + 3;

    cout << *p;

    return 0;


    // int q, n, m, a, b, c, d, e, f;
    // n = 3;
    // m = 3;
    // int v[3][3];

    // int k = 1;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         // cout << '[' << i << ']' << '[' << j << ']' << " ";
    //         v[i][j] = k;
    //         k++;
    //     }
    // }

    // cout << "\n\n";
    // // cout << "\n" << v[1][1] << "\n";

    // int i = 2;
    // int j = 1;

    // //Address(a[i][j]) = ((j*m)+i)*Size + BA

    // int *ptr = *(v + i) + j;

    // // cout << "\n" << *ptr << "\n";

    // int *p = *(((j * m) + i) + v);

    // cout << *p << "\n";


    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}