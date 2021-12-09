//
// Created by Kain Zhang on 2021/12/9.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 205;

int N, K, cost[mxN][mxN], c[mxN], hpy[mxN];
unordered_map<int, string> name;
unordered_map<string, int> idx;
vector<bool> vis(mxN);
vector<int> pre[mxN];

void dijkstra(int s) {
    fill(c, c + N, INT_MAX);
    c[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, minD = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && c[j] < minD) {
                minD = c[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && cost[u][v] != INT_MAX) {
                if (c[u] + cost[u][v] < c[v]) {
                    c[v] = c[u] + cost[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (c[u] + cost[u][v] == c[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

vector<int> path, t_path;
int cntR, hpyR, avgR;
void dfs(int v) {
    t_path.push_back(v);
    if (v == 0) {
        int sum = 0;
        for (int &i : t_path) {
            sum += hpy[i];
        }
        double avg = sum * 1.0 / (t_path.size() - 1);
        if (sum > hpyR) {
            hpyR = sum;
            avgR = avg;
            path = t_path;
        } else if (sum == hpyR && avg > avgR) {
            avgR = avg;
            path = t_path;
        }
        cntR++;
    }
    for (int &i : pre[v]) {
        dfs(i);
    }
    t_path.pop_back();
}

int main() {
    fill(cost[0], cost[0] + mxN * mxN, INT_MAX);
    string city0;
    cin >> N >> K >> city0;
    name[0] = city0;
    idx[city0] = 0;
    for (int i = 1; i < N; i++) {
        string ct;
        int pt;
        cin >> ct >> pt;
        hpy[i] = pt;
        name[i] = ct;
        idx[ct] = i;
    }
    for (int i = 0; i < K; i++) {
        string city1, city2;
        int cst;
        cin >> city1 >> city2 >> cst;
        int u = idx[city1], v = idx[city2];
        cost[u][v] = cost[v][u] = cst;
    }
    dijkstra(0);
    dfs(idx["ROM"]);
    cout << cntR << " " << c[idx["ROM"]] << " " << hpyR << " " << avgR << endl;
    int len = path.size();
    for (int i = len - 1; i >= 0; i--) {
        if (i < len - 1) cout << "->";
        cout << name[path[i]];
    }
}