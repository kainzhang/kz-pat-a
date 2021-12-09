//
// Created by Kain Zhang on 2021/12/9.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e5 + 5;

vector<int> G[mxN];
double P, r;

/*
 * dfs 获取最深层数
 */
int N, mxL = 0, cnt = 0;
void dfs(int root, int lyr) {
    int len = G[root].size();
    if (!len) {
        if (lyr > mxL) {
            mxL = lyr;
            cnt = 1;
        } else if (lyr == mxL) {
            cnt++;
        }
        return;
    }
    for (auto &it : G[root]) {
        dfs(it, lyr + 1);
    }
}

int main() {
    cin >> N >> P >> r;
    int root, tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (tmp == -1) {
            root = i;
        } else {
            G[tmp].push_back(i);
        }
    }
    dfs(root, 0);
    printf("%.2f %d", P * pow(1 + r / 100, mxL), cnt);
}