//
// Created by Kain Zhang on 2021/12/11.
//

#include "bits/stdc++.h"
using namespace std;

/*
 * 0: default
 * 1: stucked
 * -1: ain't stucked
 */
unordered_map<char, int> mp;

int main() {
    int k;
    cin >> k;
    getchar();
    string str;
    getline(cin, str);
    vector<char> stuc;
    int len = str.size(), cnt = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] == str[i + 1]) {
            cnt++;
        } else {
            if (cnt % k == 0) {
                if (mp[str[i]] != -1) {
                    if (mp[str[i]] == 0) {
                        stuc.push_back(str[i]);
                    }
                    mp[str[i]] = 1;
                }
            } else {
                mp[str[i]] = -1;
            }
            cnt = 1;
        }
    }
    for (char &c : stuc) {
        if (mp[c] == 1) {
            cout << c;
        }
    }
    cout << endl;
    for (int i = 0; i < len; i++) {
        cout << str[i];
        if (mp[str[i]] == 1) {
            i += k - 1;
        }
    }
}