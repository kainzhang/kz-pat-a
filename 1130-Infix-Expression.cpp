//
// Created by Kain Zhang on 2021/12/14.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 25;

struct node {
    string data;
    int chL, chR;
};

vector<node> vec(mxN);
vector<int> vis(mxN);
int root = 1;

void printInfix(int r) {
    if (r == -1) {
        return;
    }
    if (r != root && (vec[r].chL != -1 || vec[r].chR != -1)) {
        cout << "(";
    }
    printInfix(vec[r].chL);
    cout << vec[r].data;
    printInfix(vec[r].chR);
    if (r != root && (vec[r].chL != -1 || vec[r].chR != -1)) {
        cout << ")";
    }
}


int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> vec[i].data >> vec[i].chL >> vec[i].chR;
        if (vec[i].chL != -1) vis[vec[i].chL]++;
        if (vec[i].chR != -1) vis[vec[i].chR]++;
    }
    while (vis[root]) { // 找根结点，根结点不是任何结点的子节点
        root++;
    }
    printInfix(root);
}