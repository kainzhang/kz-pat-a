//
// Created by Kain Zhang on 2021/12/10.
//

#include "bits/stdc++.h"
using namespace std;

struct node {
    string addr, nxt;
    int key;
};

void printList(vector<node>& vec) {
    if (!vec.size()) return;
    cout << vec[0].addr << " " << vec[0].key;
    for (int i = 1; i < vec.size(); i++) {
        cout << " " << vec[i].addr << endl;
        cout << vec[i].addr << " " << vec[i].key;
    }
    cout << " -1" << endl;
}

int main() {
    int N;
    string fst;
    cin >> fst >> N;
    unordered_map<string, node> mp;
    for (int i = 0; i < N; i++) {
        node x;
        cin >> x.addr >> x.key >> x.nxt;
        mp[x.addr] = x;
    }
    vector<node> vec;
    string cur = fst;
    while (cur != "-1") {
        vec.push_back(mp[cur]);
        cur = mp[cur].nxt;
    }
    unordered_map<int, int> vis;
    vector<node> res, rmd;
    for (auto &it : vec) {
        if (vis[abs(it.key)]) {
            rmd.push_back(it);
        } else {
            res.push_back(it);
            vis[abs(it.key)]++;
        }
    }
    printList(res);
    printList(rmd);
}