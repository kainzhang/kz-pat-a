//
// Created by Kain Zhang on 2021/12/11.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e5 + 5;

unordered_map<int, int> birds, trees;
vector<int> dad(mxN);

int findDad(int x) {
    int a = x;
    while (x != dad[x]) {
        x = dad[x];
    };
    while (a != dad[a]) {
        int z = a;
        a = dad[a];
        dad[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int dA = findDad(a);
    int dB = findDad(b);
    if (dA != dB) {
        dad[dA] = dB;
    }
}

int main() {
    for (int i = 1; i <= mxN; i++) {
        dad[i] = i;
    }
    int N, K, fst;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        int idx;
        for (int j = 0; j < K; j++) {
            cin >> idx;
            if (j) { // 与第 1 只鸟联结
                Union(fst, idx);
            } else {
                fst = idx;
            }
            birds[idx] = 1;
        }
    }
    for (auto &it : birds) {
        trees[findDad(it.first)]++;
    }
    int Q;
    cin >> Q;
    cout << trees.size() << " " << birds.size() << endl;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        cout << (findDad(a) == findDad(b) ? "Yes" : "No") << endl;
    }
}