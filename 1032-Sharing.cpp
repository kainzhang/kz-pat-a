//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;

struct node {
    char val;
    string nxt;
};

unordered_map<string, node> mp;
unordered_map<string, int> vis;

int main() {
    int N;
    string addr_1, addr_2;
    cin >> addr_1 >> addr_2 >> N;
    for (int i = 0; i < N; i++) {
        node x;
        string addrT;
        cin >> addrT >> x.val >> x.nxt;
        mp[addrT] = x;
    }
    string addr = addr_1;
    while (addr != "-1") {
        vis[addr]++;
        addr = mp[addr].nxt;
    }
    addr = addr_2;
    while (addr != "-1") {
        vis[addr]++;
        if (vis[addr] == 2) {
            cout << addr;
            return 0;
        }
        addr = mp[addr].nxt;
    }
    cout << "-1";
}