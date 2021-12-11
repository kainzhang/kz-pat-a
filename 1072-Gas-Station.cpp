//
// Created by Kain Zhang on 2021/12/5.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e3 + 20;

int N, M, K, Ds, G[mxN][mxN], d[mxN];
bool vis[mxN];

int ans_id = -1;
double ans_dis = -1, ans_avg = DBL_MAX;
void dijkstra(int s) {
    fill(d, d + mxN, INT_MAX);
    d[s] = 0;
    fill(vis, vis + mxN, false);
    for (int i = 0; i < N + M; i++) {
        int u = -1, MIN = INT_MAX;
        for (int j = 1; j <= N + M; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 1; v <= N + M; v++) {
            if (!vis[v] && G[u][v] && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
    int minD =INT_MAX, sum = 0;
    for (int i = 1; i <= N; i++) {
        if (d[i] > Ds) {
            return;
        } else if (d[i] < minD) {
            minD = d[i];
        }
        sum += d[i];
    }
    double avg = sum * 1.0 / N;
    if (minD > ans_dis) {
        ans_id = s;
        ans_avg = avg;
        ans_dis = minD;
    } else if (minD == ans_dis && avg < ans_avg) {
        ans_id = s;
        ans_avg =avg;
    }
}

int main() {
    cin >> N >> M >> K >> Ds;
    string P1, P2;
    int a, b, dist;
    for (int i = 0; i < K; i++) {
        cin >> P1 >> P2 >> dist;
        if (P1[0] == 'G') {
            P1 = P1.substr(1);
            a = stoi(P1) + N;
        } else {
            a = stoi(P1);
        }
        if (P2[0] == 'G') {
            P2 = P2.substr(1);
            b = stoi(P2) + N;
        } else {
            b = stoi(P2);
        }
        G[a][b] = G[b][a] = dist;
    }
    for (int i = N + 1; i <= N + M; i++) {
        dijkstra(i);
    }
    if (ans_id == -1) {
        printf("No Solution");
    } else {
        printf("G%d\n%.1f %.1f", ans_id - N, ans_dis, ans_avg);
    }
}