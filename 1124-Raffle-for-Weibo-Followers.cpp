//
// Created by Kain Zhang on 2021/12/12.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int M, N, S, flag = 0;
    cin >> M >> N >> S;
    string ncnm;
    unordered_map<string, int> mp;
    for (int i = 1; i <= M; i++) {
        cin >> ncnm;
        if (i == S) {
            if (!mp[ncnm]) {
                cout << ncnm << endl;
                flag++;
                S += N;
            } else {
                S++;
            }
            mp[ncnm]++;
        }
    }
    if (!flag) {
        cout << "Keep going...";
    }
}