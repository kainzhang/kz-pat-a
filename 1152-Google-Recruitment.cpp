//
// Created by Kain Zhang on 2021/12/14.
//

#include "bits/stdc++.h"
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int L, K;
    string N;
    cin >> L >> K >> N;
    for (int i = 0; i <= L - K; i++) {
        string t = N.substr(i, K);
        int num = stoi(t);
        if (isPrime(num)) {
            cout << t;
            return 0;
        }
    }
    cout << "404";
}