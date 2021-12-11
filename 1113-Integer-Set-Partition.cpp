//
// Created by Kain Zhang on 2021/12/11.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int S1 = 0, S2 = 0;
    for (int i = 0; i < N; i++) {
        if (i < N / 2) {
            S1 += vec[i];
        } else {
            S2 += vec[i];
        }
    }
    cout << N % 2 << " " << S2 - S1;
}