//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;

bool isPalidromicNum(string str) {
    int len = str.size();
    for (int i = 0; i <= len / 2; i++) {
        if (str[i] != str[len - i - 1]) return false;
    }
    return true;
}

string getSum(string str) {
    string res = str;
    int len = str.size(), tmp = 0;
    for (int i = len - 1; i >= 0; i--) {
        tmp += res[i] - '0' + str[len - i - 1] - '0';
        res[i] = tmp % 10 + '0';
        tmp /= 10;
    }
    return (tmp ? "1" + res : res);
}

int main() {
    string N;
    int K, i;
    cin >> N >> K;
    for (i = 0; i < K; i++) {
        if (isPalidromicNum(N)) {
            break;
        }
        N = getSum(N);
    }
    cout << N << endl << i;
}