//
// Created by Kain Zhang on 2021/11/29.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 35;

int post[mxN], in[mxN], G[mxN][3];

int buildTree(int postL, int postR, int inL, int inR) {
    if (postL > postR)
        return -1;
    int k = inL;
    while (k <= inR) {
        if (in[k] == post[postR])
            break;
        k++;
    }
    int num_left = k - inL;
    G[post[postR]][0] = buildTree(postL, postL + num_left - 1, inL, k - 1);
    G[post[postR]][1] = buildTree(postL + num_left, postR - 1, k + 1, inR);
    return post[postR];
}

void printLvOrder(int r) {
    queue<int> que;
    que.push(r);
    int flag = 0;
    while (!que.empty()) {
        r = que.front();
        que.pop();
        if (flag++) cout << " ";
        cout << r;
        if (G[r][0] != -1) que.push(G[r][0]);
        if (G[r][1] != -1) que.push(G[r][1]);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> post[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
    int r = buildTree(0, N - 1, 0, N - 1);
    printLvOrder(r);
}