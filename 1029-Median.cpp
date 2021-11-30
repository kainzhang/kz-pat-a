//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 2e5 + 5;

vector<int> S1(mxN);

int main() {
    int N1, N2;
    cin >> N1;
    for (int i = 0; i < N1; i++) {
        cin >> S1[i];
    }
    S1[N1] = INT_MAX;
    cin >> N2;
    int mid = (N1 + N2 - 1) / 2, s2, i1 = 0, i2 = 0, cnt = 0;
    cin >> s2;
    while (cnt++ < mid) {
        if (S1[i1] < s2) {
            i1++;
        } else {
            if (++i2 < N2) {
                cin >> s2;
            } else {
                s2 = INT_MAX;
            }
        }
    }
    cout << (S1[i1] < s2 ? S1[i1] : s2) << endl;
}