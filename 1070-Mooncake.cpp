 //
// Created by Kain Zhang on 2021/12/5.
//

#include "bits/stdc++.h"
using namespace std;

struct cake {
    double amt, prc;
    bool operator < (const cake &x) const {
        return prc / amt > x.prc / x.amt;
    }
};

int main() {
    int N, D;
    cin >> N >> D;
    vector<cake> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].amt;
    }
    for (int i = 0; i < N; i++) {
        cin >> vec[i].prc;
    }
    sort(vec.begin(), vec.end());
    double ans = 0;
    for (auto &it : vec) {
        if (it.amt >= D) {
            ans += D * it.prc / it.amt;
            break;
        } else {
            D -= it.amt;
            ans += it.prc;
        }
    }
    printf("%.2f", ans);
}