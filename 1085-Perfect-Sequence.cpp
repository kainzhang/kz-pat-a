//
// Created by Kain Zhang on 2021/12/8.
//

#include "bits/stdc++.h"
using namespace std;
using LL = long long;

int main() {
    int N, p;
    cin >> N >> p;
    vector<LL> vec(N);
    for (int i = 0; i < vec.size(); i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    LL i = 0, j = 0, ans = 0;
    while (i < N) {
        LL tmp = vec[i] * p;
        while (vec[j] <= tmp && j < N) {
            j++;
        }
        ans = max(ans, j - i);
        i++;
    }
    cout << ans;
}