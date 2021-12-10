//
// Created by Kain Zhang on 2021/12/10.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e2 + 5;

vector<int> mp[mxN], cnt(mxN);

int mxP = 0, lyrNum;
void dfs(int root, int lyr) {
    cnt[lyr]++;
    if (cnt[lyr] > mxP) {
        mxP = cnt[lyr];
        lyrNum = lyr;
    }
    for (int &it : mp[root]) {
        dfs(it, lyr + 1);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int ID, tid, K;
        cin >> ID >> K;
        while (K--) {
            cin >> tid;
            mp[ID].push_back(tid);
        }
    }
    dfs(1, 1);
    cout << mxP << " " << lyrNum;
}