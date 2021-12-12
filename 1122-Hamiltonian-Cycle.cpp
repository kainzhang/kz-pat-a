//
// Created by Kain Zhang on 2021/12/12.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 205;

int G[mxN][mxN];

int main() {
    int N, M, K;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = G[v2][v1] = 1;
    }
    cin >> K;
    while (K--) {
        int n;
        cin >> n;
        vector<int> vis(N + 1);
        int fst, pre, cur, flag = 1;
        for (int i = 0; i < n; i++) {
            if (!i) {
                cin >> fst;
                pre = fst;
            } else {
                cin >> cur;
                vis[cur]++;
                if (!G[pre][cur] || vis[cur] == 2) {
                    flag = 0;
                }
                pre = cur;
            }
        }
        if (cur != fst || n != N + 1) {
            flag = 0;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}