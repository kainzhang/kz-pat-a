//
// Created by Kain Zhang on 2021/12/10.
//

#include "bits/stdc++.h"
using namespace std;

/*
 * 1 3 2 4 5
 * 1 2 3 4 5
 */

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    int mxI = -INT_MAX;
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        mxI = max(mxI, b[i]);
        if (a[i] == b[i] && b[i] == mxI) {
            ans.push_back(b[i]);
        }
    }
    int len = ans.size();
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}