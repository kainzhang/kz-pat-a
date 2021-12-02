//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N, ans = 0, a = 1;
    cin >> N;
    while (N / a) {            // 从右到左依次处理数字
        int now = N / a % 10;  // 当前处理的数字
        int l = N / (a * 10);  // 左边的数
        int r = N % a;         // 右边的数
        if (!now) {
            ans += l * a;
        } else if (now == 1) {
            ans += l * a + 1 + r;
        } else {  // now > 1
            ans += (l + 1) * a;
        }
        a *= 10; // 从个位开始，不断乘 10
    }
    cout << ans;
}