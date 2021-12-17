//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;

unordered_map<int, int> mp;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int num;
        cin >> num;
        mp[num] = i;
    }
    int L;
    cin >> L;
    vector<int> vec;
    for (int i = 0; i < L; i++) {
        int num;
        cin >> num;
        if (!mp[num]) continue;
        vec.push_back(mp[num]);
    }
    int len = vec.size();
    vector<int> dp(len + 1);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (vec[i] >= vec[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
}