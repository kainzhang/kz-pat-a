//
// Created by LOKKA on 2020/9/4.
//

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL str2Dec(string str, LL radix) {
    LL res = 0, tmp;
    int len = str.size();
    for (char &c : str) {
        tmp = isdigit(c) ? c - '0' : c - 'a' + 10;
        res += tmp * pow(radix, --len);
    }
    return res;
}

LL getRadix(string str, LL num) {
    char mxC = *max_element(str.begin(), str.end());
    LL lo = isdigit(mxC) ? mxC - '0' + 1 : mxC - 'a' + 11;
    LL hi = max(lo, num), res = 0;
    while (lo <= hi) {
        LL mid = (lo + hi) / 2;
        LL tmp = str2Dec(str, mid);
        if (tmp > num || tmp < 0) { // 有溢出情况
            hi = mid - 1;
        } else if (tmp == num) {
            res = mid;
            break;
        } else {
            lo = mid + 1;
        }
    }
    return res;
}

int main() {
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    LL num = (tag & 1) ? str2Dec(N1, radix) : str2Dec(N2, radix);
    LL rdx = (tag & 1) ? getRadix(N2, num) : getRadix(N1, num);
    if (rdx) {
        cout << rdx;
    } else {
        cout << "Impossible";
    }
}