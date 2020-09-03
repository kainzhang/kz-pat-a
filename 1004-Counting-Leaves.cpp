//
// Created by LOKKA on 2020/9/3.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 105;

vector<int> G[mxN], lyr(mxN);
int mxL = -1;

void dfs(int r, int l) {
    if (!G[r].size()) {
        lyr[l]++;
        mxL = max(mxL, l);
    } else {
        for (int &i : G[r]) {
            dfs(i, l + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K, dad, chd;
    cin >> N >> M;
    while (M--) {
        cin >> dad >> K;
        while (K--) {
            cin >> chd;
            G[dad].push_back(chd);
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= mxL; i++) {
        if (i) cout << " ";
        cout << lyr[i];
    }
}