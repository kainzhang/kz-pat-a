//
// Created by Kain Zhang on 2021/12/4.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e4 + 5;

int N, idx = 0;
vector<int> vec(mxN), ans(mxN);

void getLvOrder(int r) {
    if (r > N) return;
    getLvOrder(r * 2); // left child
    ans[r] = vec[idx++];
    getLvOrder(r * 2 + 1); // right child
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.begin() + N); // 得到中序遍历
    getLvOrder(1);
    for (int i = 1; i <= N; i++) {
        if (i > 1) cout << " ";
        cout << ans[i];
    }
}