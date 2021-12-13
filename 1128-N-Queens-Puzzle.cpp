//
// Created by Kain Zhang on 2021/12/13.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int K;
    cin >> K;
    while (K--) {
        int N, t, flag = 1;
        cin >> N;
        vector<int> vec;
        for (int i = 0; i < N; i++) {
            cin >> t;
            vec.push_back(t);
            int l = t - 1, r = t + 1;
            for (int j = i - 1; j >= 0 && flag; j--) {
                if (vec[j] == t || vec[j] == l || vec[j] == r) {
                    flag = 0;
                }
                l--, r++;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}