//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 505;

int N, M, S, D;
int G[mxN][mxN], d[mxN], cost[mxN][mxN], c[mxN], pas[mxN];
bool vis[mxN] = {false};

void dijkstra(int s) {
    fill(d, d + N, INT_MAX);
    d[s] = 0;
    fill(c, c + N, INT_MAX);
    c[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, MIN = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && G[u][v]) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                    pas[v] = u;
                } else if (d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]) {
                    c[v] = c[u] + cost[u][v];
                    pas[v] = u;
                }
            }
        }
    }
}

void printPath(int v) {
    if (v == S) {
        cout << v << " ";
        return;
    }
    printPath(pas[v]);
    cout << v << " ";
}

int main() {
    cin >> N >> M >> S >> D;
    for (int i = 0; i < M; i++) {
        int c1, c2, dd, cc;
        cin >> c1 >> c2 >> dd >> cc;
        G[c1][c2] = G[c2][c1] = dd;
        cost[c1][c2] = cost[c2][c1] = cc;
    }
    dijkstra(S);
    printPath(D);
    cout << d[D] << " " << c[D];
}