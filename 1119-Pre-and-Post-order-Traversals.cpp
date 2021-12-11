//
// Created by Kain Zhang on 2021/12/11.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 35;

vector<int> pre(mxN), post(mxN), in;

bool is_unique = true;
void getInOrder(int preL, int preR, int postL, int postR) {
    if (preL == preR) {
        in.push_back(pre[preL]);
        return;
    }
    if (pre[preL] == post[postR]) {
        int i = preL + 1;
        while (i <= preR && pre[i] != post[postR - 1]) {
            i++;
        }
        if (i - preL > 1) {
            getInOrder(preL + 1, i - 1, postL, postL + (i - preL - 1) - 1);
        } else {
            is_unique = false;
        }
        in.push_back(post[postR]);
        getInOrder(i, preR, postL + (i - preL - 1), postR - 1);
    }
}

int main() {
    int N;
    cin >> N;
    pre.resize(N), post.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> post[i];
    }
    getInOrder(0, N - 1, 0, N - 1);
    cout << (is_unique ? "Yes" : "No") << endl;
    for (int i = 0; i < in.size(); i++) {
        if (i) cout << " ";
        cout << in[i];
    }
    cout << endl;
}