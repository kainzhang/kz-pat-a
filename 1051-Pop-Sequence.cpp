//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N, K;
    cin >> M >> N >> K;
    while (K--) {
        vector<int> vec(N);
        for (int i = 0; i < N; i++) {
            cin >> vec[i];
        }
        bool ok = true;
        int idx = 0;
        stack<int> stk;
        for (int i = 1; i <= N; i++) {
            stk.push(i);
            if (stk.size() > M) {
                ok = false;
                break;
            }
            while (!stk.empty() && stk.top() == vec[idx]) {
                stk.pop();
                idx++;
            }
        }
        if (idx != N) {
            ok = false;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}