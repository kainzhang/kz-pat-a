//
// Created by Kain Zhang on 2021/12/11.
//

#include "bits/stdc++.h"
using namespace std;

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, K;
    cin >> N;
    unordered_map<string, int> mp;
    string ID;
    for (int i = 1; i <= N; i++) {
        cin >> ID;
        mp[ID] = i;
    }
    cin >> K;
    while (K--) {
        cin >> ID;
        cout << ID << ": ";
        if (mp[ID] == -1) {
            cout << "Checked" << endl;
        } else if (!mp[ID]) {
            cout << "Are you kidding?" << endl;
        } else {
            if (mp[ID] == 1) {
                cout << "Mystery Award" << endl;
            } else if (isPrime(mp[ID])) {
                cout << "Minion" << endl;
            } else {
                cout << "Chocolate" << endl;
            }
            mp[ID] = -1;
        }
    }
}