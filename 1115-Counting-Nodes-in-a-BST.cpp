//
// Created by Kain Zhang on 2021/12/11.
//

#include "bits/stdc++.h"
using namespace std;

struct node {
    int data;
    node *chdL, *chdR;
};

node* buildTree(node *root, int num) {
    if (root == NULL) {
        root = new node();
        root->data = num;
        root->chdL = root->chdR = NULL;
    } else if (num <= root->data) {
        root->chdL = buildTree(root->chdL, num);
    } else {
        root->chdR = buildTree(root->chdR, num);
    }
    return root;
}

unordered_map<int, int> L;
int mxL = -1;
void dfs(node *root, int lyr) {
    if (root == NULL) return;
    L[lyr]++;
    mxL = max(mxL, lyr);
    dfs(root->chdL, lyr + 1);
    dfs(root->chdR, lyr + 1);
}

int main() {
    int N;
    cin >> N;
    node *root = NULL;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        root = buildTree(root, num);
    }
    dfs(root, 0);
    printf("%d + %d = %d", L[mxL], L[mxL - 1], L[mxL] + L[mxL - 1]);
}