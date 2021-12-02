//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 60;

string sign = "SHCDJ";
vector<int> card(mxN), op(mxN);

int main() {
    for (int i = 1; i < 55; i++) {
        card[i] = i;
    }
    int K;
    cin >> K;
    for (int i = 1; i < 55; i++) {
        cin >> op[i];
    }
    vector<int> pcard(card.begin(), card.end());
    while (K--) {
        for (int i = 1; i < 55; i++) {
            pcard[op[i]] = card[i];
        }
        card = pcard;
    }
    for (int i = 1; i < 55; i++) {
        if (i > 1) cout << " ";
        // 注意 13/13 = 1
        int s = (pcard[i] - 1) / 13;
        int tmp = pcard[i] % 13;
        if (tmp == 0) tmp = 13;
        cout << sign[s] << tmp;
    }
}