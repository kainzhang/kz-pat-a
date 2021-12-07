//
// Created by Kain Zhang on 2021/12/7.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    string str;
    cin >> str;
    int idx = 0;
    while (str[idx] != 'E') {
        idx++;
    }
    string numS = str.substr(1, idx - 1);
    string expS = str.substr(idx + 1);
    int exp = stoi(expS), len = numS.size();
    if (str[0] == '-') cout << '-';
    if (exp > 0) {
        int lenP = max(2 + exp, len);
        for (int i = 0; i < lenP; i++) {
            if (i < len && numS[i] == '.') continue;
            if (i == 2 + exp) {
                cout << '.';
            }
            if (i >= len) {
                cout << "0";
            } else {
                cout << numS[i];
            }
        }
    } else {
        cout << "0.";
        for (int i = 0; i < abs(exp) - 1; i++) {
            cout << "0";
        }
        for (int i = 0; i < len; i++) {
            if (numS[i] == '.') continue;
            cout << numS[i];
        }
    }
}