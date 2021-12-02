//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    cin >> M >> N;
    int haf = M * N / 2, clr;
    unordered_map<int, int> mp;
    for (int i = 0; i < M * N; i++) {
        cin >> clr;
        mp[clr]++;
        if (mp[clr] > haf) {
            cout << clr;
            return 0;
        }
    }
}