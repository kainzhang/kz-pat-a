//
// Created by Kain Zhang on 2021/12/10.
//

#include "bits/stdc++.h"
using namespace std;
const int INF = 1000000007;

int main() {
    string str;
    cin >> str;
    int p = 0, a = 0, t = 0;
    for (char &c : str) {
        switch(c) {
            case 'P': p = (p + 1) % INF; break;
            case 'A': a = (a + p) % INF; break;
            case 'T': t = (t + a) % INF; break;
        }
    }
    cout << t;
}