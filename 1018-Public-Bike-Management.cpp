//
// Created by LOKKA on 2020/9/4.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 505;

int C_max, N, S_p, M, a, b, l;
int G[mxN][mxN], weight[mxN], d[mxN], vis[mxN];
vector<int> pre[mxN], path, tmp_path;

void dijkstra(int s) {
    fill(d, d + mxN, INT_MAX);
    d[s] = 0;
    for (int i = 0; i <= N; i++) {
        int u = -1, MIN = INT_MAX;
        for (int j = 0; j <= N; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = 1;
        for (int v = 0; v <= N; v++) {
            if (!vis[v] && G[u][v] != INT_MAX) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int min_send = INT_MAX, min_back = INT_MAX;
void dfs(int v) {
    tmp_path.push_back(v);
    if (v == 0) {
        int len = tmp_path.size(), send = 0, back = 0;
        for (int u = len - 2; u >= 0; u--) {
            int num = weight[tmp_path[u]] - C_max / 2;
            if (num < 0) {
                if (back >= -num) {
                    back += num;
                } else {
                    send += -num - back;
                    back = 0;
                }
            } else {
                back += num;
            }
        }
        if (send < min_send) {
            min_send = send;
            min_back = back;
            path = tmp_path;
        } else if (send == min_send && back < min_back) {
            min_back = back;
            path = tmp_path;
        }
    }
    for (int &u : pre[v]) {
        dfs(u);
    }
    tmp_path.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(G[0], G[0] + mxN * mxN, INT_MAX);
    cin >> C_max >> N >> S_p >> M;
    for (int i = 1; i <= N; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> l;
        G[a][b] = G[b][a] = l;
    }
    dijkstra(0);
    dfs(S_p);
    cout << min_send << " ";
    for (auto i = path.rbegin(); i != path.rend(); i++) {
        if (*i) cout << "->";
        cout << *i;
    }
    cout << " " << min_back;
}