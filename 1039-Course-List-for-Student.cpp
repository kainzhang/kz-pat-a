//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;

unordered_map<string, vector<int>> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K, idx, Ni;
    string name;
    cin >> N >> K;
    while (K--) {
        cin >> idx >> Ni;
        while (Ni--) {
            cin >> name;
            mp[name].push_back(idx);
        }
    }
    while (N--) {
        cin >> name;
        cout << name << " " << mp[name].size();
        sort(mp[name].begin(), mp[name].end());
        for (auto &it : mp[name]) {
            cout << " " << it;
        }
        cout << endl;
    }
}