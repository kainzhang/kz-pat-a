//
// Created by Kain Zhang on 2021/12/5.
//

#include "bits/stdc++.h"
using namespace std;

unordered_map<int, int> mp;

int main() {
    int N, num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        mp[num] = i;
    }
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (mp[i] != i) {
            while (mp[0] != 0) {
                swap(mp[mp[0]], mp[0]);
                cnt++;
            }
        }
        if (mp[i] != i) {
            swap(mp[i], mp[0]);
            cnt++;
        }
    }
    cout << cnt;
}