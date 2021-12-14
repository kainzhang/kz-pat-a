//
// Created by Kain Zhang on 2021/12/14.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 5e5 + 5;

vector<int> pre(mxN), in(mxN);

int flag = 0;
void buildTree(int preL, int preR, int inL, int inR) {
    if (preL > preR || flag) {
        return;
    }
    int k = inL;
    while (k <= inR) {
        if (in[k] == pre[preL]) {
            break;
        }
        k++;
    }
    int numLeft = k - inL;
    buildTree(preL + 1, preL + numLeft, inL, k - 1);
    buildTree(preL + numLeft + 1, preR, k + 1, inR);
    if (!flag) {
        cout << pre[preL] << endl;
        flag++;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
    buildTree(0, N - 1, 0, N - 1);
}