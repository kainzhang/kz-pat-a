//
// Created by Kain Zhang on 2021/12/14.
//

#include "bits/stdc++.h"
using namespace std;

struct node {
    string addr, nxt;
    int data;
};

int main() {
    string fst;
    int N, K;
    cin >> fst >> N >> K;
    unordered_map<string, node> raw;
    for (int i = 0; i < N; i++) {
        node x;
        cin >> x.addr >> x.data >> x.nxt;
        raw[x.addr] = x;
    }
    vector<node> vec;
    while (fst != "-1") {
        vec.push_back(raw[fst]);
        fst = raw[fst].nxt;
    }
    vector<node> p1, p2, p3;
    for (auto &it : vec) {
        if (it.data < 0) {
            p1.push_back(it);
        } else if (it.data <= K) {
            p2.push_back(it);
        } else {
            p3.push_back(it);
        }
    }
    for (auto &it : p2) {
        p1.push_back(it);
    }
    for (auto &it : p3) {
        p1.push_back(it);
    }
    cout << p1[0].addr << " " << p1[0].data;
    for (int i = 1; i < p1.size(); i++) {
        cout << " " << p1[i].addr << endl;
        cout << p1[i].addr << " " << p1[i].data;
    }
    cout << " -1";
}