//
// Created by Kain Zhang on 2021/12/8.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e3 + 5;

int N, L, M;
vector<int> mp[mxN];

int bfs(int r, vector<bool>& vis) {
    int res = 0;
    queue<pair<int, int> > que; // 组合用户id和当前层数
    que.push(make_pair(r, 0));
    while (!que.empty()) {
        pair<int, int> x = que.front();
        que.pop();
        if (vis[x.first]) continue;
        res++;
        vis[x.first] = true;
        if (x.second < L) {
            for (int &it : mp[x.first]) {
                if (!vis[it]) {
                    que.push(make_pair(it, x.second + 1));
                }
            }
        }
    }
    return res - 1;
}

int main() {
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        cin >> M;
        while (M--) {
            int uid;
            cin >> uid;
            mp[uid].push_back(i);
        }
    }
    int K, uid;
    cin >> K;
    while (K--) {
        vector<bool> vis(mxN);
        cin >> uid;
        cout << bfs(uid, vis)<< endl;
    }
}