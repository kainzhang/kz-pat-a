//
// Created by Kain Zhang on 2021/12/14.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    while (N--) {
        int num;
        cin >> num;
        if (num > 0) {
            mp[num]++;
        }
    }
    int cur = 1;
    while (1) {
        if (!mp[cur]) {
            cout << cur;
            return 0;
        }
        cur++;
    }
}