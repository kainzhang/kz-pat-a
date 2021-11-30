//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    string str;
    cin >> str;
    int N = str.size();
    int n1 = (N + 2) / 3;
    int n2 = N + 2 - 2 * n1;
    for (int i = 0; i < n1 - 1; i++) {
        string line(n2, ' ');
        line[0] = str[i];
        line[n2 - 1] = str[N - i - 1];
        cout << line << endl;
    }
    cout << str.substr(n1 - 1, n2);
}