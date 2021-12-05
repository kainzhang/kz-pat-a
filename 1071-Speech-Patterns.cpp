//
// Created by Kain Zhang on 2021/12/5.
//

#include "bits/stdc++.h"
using namespace std;

map<string, int> mp;

int main() {
    string str, tmp;
    getline(cin, str);
    int len = str.size();
    // 注意 tmp 遍历完最后的处理
    for (int i = 0; i <= len; i++) {
        if (isalnum(str[i])) {
            tmp.push_back(tolower(str[i]));
        } else {
            if (tmp.size()) {
                mp[tmp]++;
                tmp.clear();
            }
        }
    }
    int mx = 0;
    string ans;
    for (auto &it : mp) {
        if (it.second > mx) {
            mx = it.second;
            ans = it.first;
        }
    }
    cout << ans << " " << mx;
}