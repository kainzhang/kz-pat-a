//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e4 + 5;

vector<int> G[mxN], tmp;
vector<bool> vis(mxN);

int maxH = 0;
void dfs(int r, int h) {
    vis[r] = true;
    if (h > maxH) {
        maxH = h;
        tmp.clear();
        tmp.push_back(r);
    } else if (h == maxH) {
        tmp.push_back(r);
    }
    for (int &i : G[r]) {
        if (!vis[i]) dfs(i, h + 1);
    }
}

int main() {
    int N, u, v;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int K = 0; // connected components
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i, 0);
            K++;
        }
    }

    if (K > 1) { // the given graph isn't a tree
        cout << "Error: " << K << " components" << endl;
        return 0;
    }

    // save the res of the first time dfs
    set<int> ans(tmp.begin(), tmp.end());

    fill(vis.begin(), vis.end(), false);
    dfs(tmp[0], 0);
    for (int &i : tmp) {
        ans.insert(i);
    }
    for (auto &i : ans) {
        cout << i << endl;
    }
}