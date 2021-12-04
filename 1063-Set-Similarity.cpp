//
// Created by Kain Zhang on 2021/12/4.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, M, num;
    cin >> N;
    set<int> seq[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> M;
        while (M--) {
            cin >> num;
            seq[i].insert(num);
        }
    }
    int K, a, b;
    cin >> K;
    while (K--) {
        cin >> a >> b;
        int nc = 0;
        for (auto &it : seq[a]) {
            if (seq[b].find(it) != seq[b].end()) {
                nc++;
            }
        }
        printf("%.1f%\n", nc * 100.0 / (seq[a].size() + seq[b].size() - nc));
    }
}