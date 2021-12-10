//
// Created by Kain Zhang on 2021/12/10.
//

#include "bits/stdc++.h"
using namespace std;

unordered_map<char, int> mp;

int main() {
    string shop, eva;
    cin >> shop >> eva;
    for (char &c : shop) {
        mp[c]++;
    }
    int cnt = 0;
    bool ok = true;
    for (char &c : eva) {
        if (mp[c]) {
            mp[c]--;
        } else {
            ok = false;
            cnt++;
        }
    }
    if (ok) {
        cout << "Yes" << " " << shop.size() - eva.size();
    } else {
        cout << "No" << " " << cnt;
    }
}