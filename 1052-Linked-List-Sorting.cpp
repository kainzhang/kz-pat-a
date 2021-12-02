//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;

struct node {
    string addr, nxt;
    int key;
    bool operator < (const node &x) const {
        return key < x.key;
    }
};

unordered_map<string, node> mp;
vector<node> vec;

int main() {
    int N;
    string addrS, addr, nxt;
    cin >> N >> addrS;
    for (int i = 0; i < N; i++) {
        node x;
        cin >> x.addr >> x.key >> x.nxt;
        mp[x.addr] = x;
    }
    while (addrS != "-1") {
        node tmp = mp[addrS];
        vec.push_back(tmp);
        addrS = tmp.nxt;
    }
    sort(vec.begin(), vec.end());
    int len = vec.size();
    if (!len) {
        cout << "0 -1" << endl;
        return 0;
    }
    cout << len << " " << vec[0].addr << endl;
    cout << vec[0].addr << " " << vec[0].key;
    for (int i = 1; i < len; i++) {
        cout << " " << vec[i].addr << endl;
        cout << vec[i].addr << " " << vec[i].key;
    }
    cout << " -1";
}