//
// Created by Kain Zhang on 2021/12/9.
//

#include "bits/stdc++.h"
using namespace std;

vector<int> pre, in;
stack<int> stk;
int N, flag = 0;

// 前序 + 中序生成树, 打印后序
void buildTree(int preL, int preR, int inL, int inR) {
    if (preL > preR) return;
    int k = inL;
    while (k <= inR) {
        if (in[k] == pre[preL]) {
            break;
        }
        k++;
    }
    buildTree(preL + 1, preL + k - inL, inL, k - 1);
    buildTree(preL + k -inL + 1, preR, k + 1, inR);
    if (flag++) {
        cout << " ";
    }
    cout << pre[preL];
}

int main () {
    cin >> N;
    for (int i = 0; i < 2 * N; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "Push") { // pre-order
            int num;
            cin >> num;
            pre.push_back(num);
            stk.push(num);
        } else { // in-order
            int num = stk.top();
            stk.pop();
            in.push_back(num);
        }
    }
    buildTree(0, N - 1, 0, N - 1);
}