//
// Created by Kain Zhang on 2021/12/7.
//

#include "bits/stdc++.h"
using namespace std;

struct node {
    string addr, next;
    int data;
};

unordered_map<string, node> mp;

int flag = 0;
void printKNodes(vector<node>& vec, int idx, int cnt) {
    if (flag++) {
        cout << vec[idx].addr << endl;
    }
    cout << vec[idx].addr << " " << vec[idx].data << " ";
    if (cnt) {
        printKNodes(vec, idx - 1, cnt - 1);
    }
}

int main() {
    string head;
    int N, K;
    cin >> head >> N >> K;
    node x;
    for (int i = 0; i < N; i++) {
        cin >> x.addr >> x.data >> x.next;
        mp[x.addr] = x;
    }
    vector<node> vec;
    while (head != "-1") {
        vec.push_back(mp[head]);
        head = mp[head].next;
    }
    for (int i = 1; i <= vec.size(); i++) {
        if (i % K == 0) {
            printKNodes(vec, i - 1, K - 1);
        }
    }
    int rest = vec.size() % K;
    for (int i = vec.size() - rest; i < vec.size() ; i++) {
        cout << vec[i].addr << endl;
        cout << vec[i].addr << " " << vec[i].data << " ";
    }
    cout << "-1";
}