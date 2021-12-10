//
// Created by Kain Zhang on 2021/12/10.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    long double ans = 0, num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        ans += num * (N - i) * (i + 1);
    }
    printf("%.2Lf", ans);
}