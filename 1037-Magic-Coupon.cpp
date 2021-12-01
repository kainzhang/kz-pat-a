//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int nC, nP;
    cin >> nC;
    vector<int> vecC(nC);
    for (int i = 0; i < nC; i++) {
        cin >> vecC[i];
    }
    sort(vecC.begin(), vecC.end());

    cin >> nP;
    vector<int> vecP(nP);
    for (int i = 0; i < nP; i++) {
        cin >> vecP[i];
    }
    sort(vecP.begin(), vecP.end());

    long long ans = 0;
    int iC = nC - 1, iP = nP - 1;
    while (vecC[iC] > 0 && vecP[iP] > 0) {
        ans += vecC[iC--] * vecP[iP--];
    }
    iC = 0, iP = 0;
    while (vecC[iC] < 0 && vecP[iP] < 0) {
        ans += vecC[iC++] * vecP[iP++];
    }
    cout << ans;
}