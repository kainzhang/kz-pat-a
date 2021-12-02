//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<int> vec(N * 2 + 5);
    for (int i = 1; i <= N; i++) {
        cin >> vec[i];
        vec[i] += vec[i - 1]; // 记录从 1 出口到 i+1 出口的距离
    }
    cin >> M;
    int a, b;
    while (M--) {
        cin >> a >> b;
        // 不出界[1, N]
        int res1 = abs(vec[b - 1] - vec[a - 1]), res2;

        // 出界
        if (a < b) { // 从 a 出发向左
            res2 = vec[a - 1] + vec[N] - vec[b - 1];
        } else { // 从 a 出发向右
            res2 = vec[b - 1] + vec[N] - vec[a - 1];
        }
        cout << min(res1, res2) << endl;
    }
}