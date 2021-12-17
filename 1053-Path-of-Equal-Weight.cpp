//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 105;

int N, M, S;
vector<int> w(mxN), G[mxN], path;

bool cmp(const int& a, const int& b) {
    return w[a] > w[b];
}

void dfs(int r, int sum) {
    path.push_back(r);
    sum += w[r];
    int len = G[r].size();
    if (len) {
        sort(G[r].begin(), G[r].end(), cmp);
        for (auto &it : G[r]) {
            dfs(it, sum);
        }
    } else if (sum == S) {
        for (int i = 0; i < path.size(); i++) {
            if (i) cout << " ";
            cout << w[path[i]];
        }
        cout << endl;
    }
    path.pop_back();
}

int main() {
    cin >> N >> M >> S;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < M; i++) {
        int id, k, t;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            G[id].push_back(t);
        }
    }
    dfs(0, 0);
}