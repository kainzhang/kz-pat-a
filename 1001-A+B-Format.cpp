//
// Created by LOKKA on 2020/9/3.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    string str = to_string(a + b);
    int len = str.size(), i = 0;
    int tmp = len % 3;
    if (str[0] == '-') {
        cout << str[i++];
    }
    for ( ; i < len; i++) {
        cout << str[i];
        if (i < len - 1 && (i + 1) % 3 == tmp) {
            cout << ",";
        }
    }
}