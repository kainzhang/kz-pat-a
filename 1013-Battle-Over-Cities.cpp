//
// Created by LOKKA on 2020/9/4.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1005;

vector<int> G[mxN], vis(mxN);

void dfs(int x, int lost) {
    for (int &i : G[x]) {
        if (i != lost && !vis[i]) {
            vis[i] = 1;
            dfs(i, lost);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K, a, b;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    while (K--) {
        fill(vis.begin(), vis.end(), 0);
        int cc = 0, lost;
        cin >> lost;
        for (int i = 1; i <= N; i++) {
            if (i != lost && !vis[i]) {
                vis[i] = 1;
                dfs(i, lost);
                cc++;
            }
        }
        cout << cc - 1 << endl; // 连通分量数 - 1
    }
}