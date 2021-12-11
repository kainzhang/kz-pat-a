//
// Created by Kain Zhang on 2021/12/11.
//

#include "bits/stdc++.h"
using namespace std;

/*
 *  英里数大于等于天数 mileVal > dayIdx +
 *               +
 *  0 1 2 3 4  5 6 7 8 9
 *  6 7 6 9 3 10 8 2 7 8
 * 10 9 8 8 7  7 6 6 3 2
 */

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), greater<>());
    int i = 0;
    while (vec[i] > i + 1) {
        i++;
    }
    cout << i;
}