//
// Created by LOKKA on 2020/9/3.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 505;

int N, M, C1, C2;
int G[mxN][mxN], weit[mxN], vis[mxN], d[mxN], w[mxN], num[mxN];

void dijkstra(int s) {
    fill(d, d + N, INT_MAX);
    d[s] = 0;
    num[s] = 1;
    w[s] = weit[s];
    for (int i = 0; i < N; i++) {
        int u = -1, MIN = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = 1;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && G[u][v] != INT_MAX) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weit[v];
                    num[v] = num[u];
                } else if (d[u] + G[u][v] == d[v]) {
                    w[v] = max(w[v], w[u] + weit[v]);
                    num[v] += num[u];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(G[0], G[0] + mxN * mxN, INT_MAX);
    cin >> N >> M >> C1 >> C2;
    for (int i = 0; i < N; i++) {
        cin >> weit[i];
    }
    int u, v, t;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> t;
        G[u][v] = G[v][u] = t;
    }
    dijkstra(C1);
    cout << num[C2] << " " << w[C2];
}