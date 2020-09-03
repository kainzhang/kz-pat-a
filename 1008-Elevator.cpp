//
// Created by LOKKA on 2020/9/3.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, now = 0, nxt, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nxt;
        if (nxt > now) {
            ans += (nxt - now) * 6 + 5;
        } else {
            ans += (now - nxt) * 4 + 5;
        }
        now = nxt;
    }
    cout << ans;
}