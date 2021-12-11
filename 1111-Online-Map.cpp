//
// Created by Kain Zhang on 2021/12/11.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 505;

int N, M, dis[mxN][mxN], tim[mxN][mxN];
bool vis[mxN];
int d[mxN], t[mxN], preD[mxN], preT[mxN], c[mxN];

// shortest path
void dijkstraD(int s) {
    fill(vis, vis + mxN, false);
    fill(d, d + mxN, INT_MAX);
    fill(t, t + mxN, INT_MAX);
    d[s] = t[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, minD = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && d[j] < minD) {
                minD = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && dis[u][v] != INT_MAX) {
                if (d[u] + dis[u][v] < d[v]) {
                    d[v] = d[u] + dis[u][v];
                    t[v] = t[u] + tim[u][v];
                    preD[v] = u;
                } else if (d[u] + dis[u][v] == d[v] && t[u] + tim[u][v] < t[v]) {
                    t[v] = t[u] + tim[u][v];
                    preD[v] = u;
                }
            }
        }
    }
}

// fastest path
void dijkstraT(int s) {
    fill(vis, vis + mxN, false);
    fill(t, t + mxN, INT_MAX);
    fill(c, c + mxN, INT_MAX);
    t[s] = c[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, minT = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && t[j] < minT) {
                minT = t[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && tim[u][v] != INT_MAX) {
                if (t[u] + tim[u][v] < t[v]) {
                    t[v] = t[u] + tim[u][v];
                    c[v] = c[u] + 1;
                    preT[v] = u;
                } else if (t[u] + tim[u][v] == t[v] && c[u] + 1 < c[v]) {
                    c[v] = c[u] + 1;
                    preT[v] = u;
                }
            }
        }
    }
}

bool isEqual(int S, int D) {
    int cur = D;
    while (cur != S) {
        if (preD[cur] != preT[cur]) {
            return false;
        }
        cur = preD[cur];
    }
    return true;
}

void printPath(int S, int D, int *pre) {
    if (D == S) {
        printf("%d", S);
        return;
    }
    printPath(S, pre[D], pre);
    printf(" -> %d", D);
}

int main() {
    fill(dis[0], dis[0] + mxN * mxN, INT_MAX);
    fill(tim[0], tim[0] + mxN * mxN, INT_MAX);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int v1, v2, ow, l, t;
        cin >> v1 >> v2 >> ow >> l >> t;
        dis[v1][v2] = l;
        tim[v1][v2] = t;
        if (!ow) {
            dis[v2][v1] = l;
            tim[v2][v1] = t;
        }
    }
    int src, dst;
    cin >> src >> dst;
    dijkstraD(src);
    dijkstraT(src);
    if (isEqual(src, dst)) {
        printf("Distance = %d; Time = %d: ", d[dst], t[dst]);
        printPath(src, dst, preD);
    } else {
        printf("Distance = %d: ", d[dst]);
        printPath(src, dst, preD);
        printf("\nTime = %d: ", t[dst]);
        printPath(src, dst, preT);
    }
}