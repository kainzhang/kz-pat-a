//
// Created by Kain Zhang on 2021/12/9.
//

#include "bits/stdc++.h"
using namespace std;

int M, N, L, T, G[65][1300][130];
int dh[] = {1, 0, 0, 0, 0, -1}, dx[] = {0, 0, 1, 0, -1, 0}, dy[] = {0, -1, 0, 1, 0, 0};

struct node {
    int x, y, h;
};

int bfs(int h, int x, int y) {
    queue<node> que;
    que.push(node{x, y, h});
    int cnt = 0;
    while (!que.empty()) {
        node nd = que.front();
        que.pop();
        cnt++;
        for (int i = 0; i < 6; i++) {
            int th = nd.h + dh[i];
            int tx = nd.x + dx[i];
            int ty = nd.y + dy[i];
            if (th < 0 || th >= L || tx < 0 || tx >= M || ty < 0 || ty >= N || !G[th][tx][ty]) {
                continue;
            }
            G[th][tx][ty] = 0;
            que.push(node{tx, ty, th});
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%d", &G[i][j][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (G[i][j][k]) {
                    G[i][j][k] = 0;
                    int tmp = bfs(i, j, k);
                    if (tmp >= T) ans += tmp;
                }
            }
        }
    }
    cout << ans;
}