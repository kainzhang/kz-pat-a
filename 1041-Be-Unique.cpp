//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;

unordered_map<int, int> cnt;

int main() {
    int N, num;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        cnt[vec[i]]++;
    }
    for (int &i : vec) {
        if (cnt[i] == 1) {
            cout << i;
            return 0;
        }
    }
    cout << "None";
}