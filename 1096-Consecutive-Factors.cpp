//
// Created by Kain Zhang on 2021/12/10.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, l = 0, r = 0, mxL = 0;
    cin >> N;
    for (int i = 2, j; i <= sqrt(N); i++) {
        int t = 1;
        for (j = i; ; j++) {
            t *= j;
            if (N % t != 0) {
                break;
            }
        }
        if (j - i > mxL) {
            mxL = j - i;
            l = i;
            r = j;
        }
    }
    if (!mxL) {
        cout << '1' << endl << N;
    } else {
        cout << mxL << endl;
        for (int i = l; i < r; i++) {
            if (i > l) {
                cout << '*';
            }
            cout << i;
        }
    }
}