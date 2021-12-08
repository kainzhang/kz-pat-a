//
// Created by Kain Zhang on 2021/12/8.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e5 + 5;

vector<int> G[mxN];
vector<double> amt(mxN);

int N;
double P, r, ans = 0;

void dfs(int root, int l) {
    int len = G[root].size();
    if (!len) {
        ans += P * pow((1 + r / 100), l) * amt[root];
        return;
    }
    for (int i = 0; i < len; i++) {
        dfs(G[root][i], l + 1);
    }
}

int main() {
    cin >> N >> P >> r;
    for (int i = 0; i < N; i++) {
        int K, id;
        cin >> K;
        if (K) {
            while (K--) {
                cin >> id;
                G[i].push_back(id);
            }
        } else {
            double a;
            cin >> a;
            amt[i] = a;
        }
    }
    dfs(0, 0);
    printf("%.1f", ans);
}