//
// Created by Kain Zhang on 2021/12/14.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, M, a, b;
    cin >> N >> M;
    vector<pair<int, int>> edg;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        edg.emplace_back(a, b);
    }
    int K;
    cin >> K;
    while (K--) {
        int Nv;
        cin >> Nv;
        vector<int> vtx(N + 1);
        while(Nv--) {
            int x;
            cin >> x;
            vtx[x]++;
        }
        int flag = 0;
        for (auto &it : edg) {
            if (!vtx[it.first] && !vtx[it.second]) {
                cout << "No" << endl;
                flag++;
                break;
            }
        }
        if (!flag) {
            cout << "Yes" << endl;
        }
    }
}
