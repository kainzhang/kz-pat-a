//
// Created by Kain Zhang on 2021/12/12.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int num, sum = 0;
        cin >> num;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        mp[sum]++;
    }
    cout << mp.size() << endl;
    int flag = 0;
    for (auto &it : mp) {
        if (flag++) {
            cout << " ";
        }
        cout << it.first;
    }
}