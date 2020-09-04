//
// Created by LOKKA on 2020/9/4.
//

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    int sqr = (int)sqrt(x);
    for (int i = 2; i <= sqr; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int getRevWithRadix(int x, int r) {
    int res = 0;
    while (x) {
        res = res * r + x % r;
        x /= r;
    }
    return res;
}

int main() {
    int N, D;
    while (cin >> N, N >= 0) {
        cin >> D;
        if (isPrime(N)) {
            int rN = getRevWithRadix(N, D);
            cout << (isPrime(rN) ? "Yes" : "No") << endl;
        } else {
            cout << "No" << endl;
        }
    }
}