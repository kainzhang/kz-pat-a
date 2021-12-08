//
// Created by Kain Zhang on 2021/12/8.
//

#include "bits/stdc++.h"
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int MSize, N;
    cin >> MSize >> N;
    while (!isPrime(MSize)) {
        MSize++;
    }
    vector<bool> vis(N);
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        int num, flag = 0;
        cin >> num;
        for (int j = 0; j < MSize; j++) {
            int pos = (num + j * j) % MSize;
            if (!vis[pos]) {
                vis[pos] = true;
                ans.push_back(pos);
                flag++;
                break;
            }
        }
        if (!flag) {
            ans.push_back(-1);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        if (ans[i] == -1) {
            cout << "-";
        } else {
            cout << ans[i];
        }
    }
}