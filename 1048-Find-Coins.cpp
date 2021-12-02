//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int lo = 0, hi = N - 1;
    while (lo < hi) {
        if (vec[lo] + vec[hi] == M) {
            cout << vec[lo] << " " << vec[hi];
            return 0;
        } else if (vec[lo] + vec[hi] > M) {
            hi--;
        } else {
            lo++;
        }
    }
    cout << "No Solution";
}