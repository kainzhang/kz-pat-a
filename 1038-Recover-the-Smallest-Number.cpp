//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b < b + a;
}

int main() {
    int N;
    cin >> N;
    vector<string> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), cmp);
    int flag = 0;
    for (auto &it : vec) {
        if (!flag) {
            int num = stoi(it);
            if (!num) continue;
            flag++;
            cout << num;
        } else {
            cout << it;
        }
    }
    if (!flag) {
        cout << "0";
    }
}