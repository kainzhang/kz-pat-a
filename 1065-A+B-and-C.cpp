//
// Created by Kain Zhang on 2021/12/4.
//

#include "bits/stdc++.h"
using namespace std;
using LL = long long;

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i <<": ";
        LL a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        LL sum = a + b;
        int flag;
        if (a > 0 && b > 0 && sum < 0) {
            // 向上溢出
            flag = 1;
        } else if (a < 0 && b < 0 && sum >= 0 ) {
            // 向下溢出
            flag = 0;
        } else {
            // 不溢出
            flag = (sum > c ? 1 : 0);
        }
        cout << (flag ? "true" : "false") << endl;
    }
}