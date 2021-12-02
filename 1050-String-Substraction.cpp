//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;

unordered_map<char, int> mp;

int main() {
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);
    for (char &c : S2) {
        mp[c]++;
    }
    for (char &c : S1) {
        if (mp[c]) continue;
        cout << c;
    }
}