//
// Created by LOKKA on 2020/9/3.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K;
    cin >> K;
    int sum = INT_MIN, tmp = 0, fst = 0, lst = K - 1, head = 0;
    vector<int> vec(K);
    for (int i = 0; i < K; i++) {
        cin >> vec[i];
        tmp += vec[i];
        if (tmp < 0) {
            tmp = 0;
            head = i + 1;
        } else if (tmp > sum) {
            sum = tmp;
            fst = head;
            lst = i;
        }
    }
    if (sum < 0) sum = 0;
    cout << sum << " " << vec[fst] << " " << vec[lst];
}