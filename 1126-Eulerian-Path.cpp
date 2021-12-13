//
// Created by Kain Zhang on 2021/12/13.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 505;

vector<int> G[mxN], vis(mxN);

void dfs(int x) {
    vis[x]++;
    for (auto &it : G[x]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
}

int main() {
    int N, M, v1, v2;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    dfs(1);
    int flag = 0;
    for (int i = 1; i <= N; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << G[i].size();
        if (G[i].size() & 1) {
            flag++;
        }
        if (!vis[i]) {
            flag = 3;
        }
    }
    cout << endl;
    if (!flag) {
        cout << "Eulerian" << endl;
    } else if (flag == 2) {
        cout << "Semi-Eulerian" << endl;
    } else {
        cout << "Non-Eulerian" << endl;
    }
}