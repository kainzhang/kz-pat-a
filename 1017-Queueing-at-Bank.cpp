//
// Created by LOKKA on 2020/9/4.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int arr, pcs;
    bool operator < (const Node &x) const {
        return arr < x.arr;
    }
};

int main() {
    int N, K, HH, MM, SS;
    scanf("%d %d", &N, &K);
    vector<Node> vec;
    for (int i = 0; i < N; i++) {
        Node tmp;
        scanf("%d:%d:%d %d", &HH, &MM, &SS, &tmp.pcs);
        tmp.arr = (HH * 60 + MM) * 60 + SS;
        if (tmp.arr > 61200) continue;
        tmp.pcs *= 60;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    priority_queue<int, vector<int>, greater<int> > que(K, 28800);
    double sum = 0;
    int len = vec.size();
    for (int i = 0; i < len; i++) {
        int L = que.top(), weit = 0;
        que.pop();
        if (L > vec[i].arr) {
            weit = L - vec[i].arr;
            L += vec[i].pcs;
        } else {
            L = vec[i].arr + vec[i].pcs;
        }
        sum += weit;
        que.push(L);
    }
    printf("%.1f\n", sum / 60 / len);
}