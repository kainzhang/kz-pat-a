//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;

vector<string> mp[2505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string name;
        int C, crs;
        cin >> name >> C;
        while (C--) {
            cin >> crs;
            mp[crs].push_back(name);
        }
    }
    for (int i = 1; i <= K; i++) {
        printf("%d %d\n", i, mp[i].size());
        sort(mp[i].begin(), mp[i].end());
        for (auto &it : mp[i]) {
            printf("%s\n", it.c_str());
        }
    }
}