//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int len = str.size(), mxL = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 1; j <= len - i; j++) {
            string strT = str.substr(i, j);
            string strR = strT;
            reverse(strR.begin(), strR.end());
            if (strT == strR) {
                mxL = max(mxL, j);
            }
        }
    }
    cout << mxL;
}

/*

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str, S = "$#";
    getline(cin, str);
    for (char c : str) {
        S += c;
        S += '#';
    }
    int mxL = 0, mxR = 0, idx = 0, len = S.size();
    vector<int> p(len);
    for (int i = 1; i < len; i++) {
        p[i] = mxL < i ? 1 : min(mxL - i, p[idx * 2 - 1]);
        while(S[i - p[i]] == S[i + p[i]]) {
            p[i]++;
        }
        if (mxL < i + p[i]) {
            mxL = i + p[i];
            idx = i;
        }
        mxR = max(mxR, p[i]);
    }
    cout << mxR - 1 << endl;
}

 */