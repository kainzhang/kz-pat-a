//
// Created by Kain Zhang on 2021/12/15.
//

#include "bits/stdc++.h"
using namespace std;

vector<pair<int, int>> edg;

int main() {
    int N, M, K;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edg.emplace_back(a, b);
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        vector<int> vtx(N);
        set<int> clr;
        for (int j = 0; j < N; j++) {
            cin >> vtx[j];
            clr.insert(vtx[j]);
        }
        bool flag = true;
        for (auto &it : edg) {
            if (vtx[it.first] == vtx[it.second]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << clr.size() << "-coloring" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}