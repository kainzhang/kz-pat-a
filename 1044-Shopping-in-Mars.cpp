//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e5 + 5;

vector<int> sum(mxN);
bool ok = false;

void binSearch(int lo, int hi, int x) {
    int L = lo;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (sum[mid] == x) {
            cout << L + 1 << "-" << mid << endl;
            ok = true;
            break;
        } else if (sum[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    while (!ok) {
        for (int i = 0; i <= N; i++) {
            binSearch(i, N, sum[i] + M);
        }
        M++;
    }
}