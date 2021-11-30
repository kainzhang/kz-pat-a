//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;

int cnt[10];

int main() {
    string str;
    getline(cin, str);
    int tmp = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        cnt[str[i] - '0']++;
        int t = (str[i] - '0') * 2 + tmp;
        str[i] = t % 10 + '0';
        cnt[t % 10]--;
        tmp = t / 10;
    }
    if (tmp) {
        str = "1" + str;
        cnt[tmp]++;
    }
    bool flag = true;
    for (int i = 0; i < 10; i++) {
        if (cnt[i] != 0) flag = false;
    }
    cout << (flag ? "Yes" : "No") << endl << str;

}