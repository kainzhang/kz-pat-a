//
// Created by Kain Zhang on 2021/12/14.
//

#include "bits/stdc++.h"
using namespace std;

/*
 * 0   1     2     3       4
 * D, D1, D111, D113, D11231, D112213111, ...
 * 从第1个开始, 描述上一个字符串
 * 1: 0th有1个D
 * 2: 1st有1个D, 1个1
 * 3: 2nd有1个D, 3个1
 * 4: 3rd有1个D, 2个1, 1个3
 */

int main() {
    string D;
    int N;
    cin >> D >> N;
    for (int i = 1; i < N; i++) {
        string tmp;
        int cnt = 1, len = D.size();
        for (int j = 1; j <= len; j++) {
            if (D[j] == D[j - 1]) {
                cnt++;
            } else {
                tmp += D[j - 1] + to_string(cnt);
                cnt = 1;
            }
        }
        D = tmp;
    }
    cout << D;
}