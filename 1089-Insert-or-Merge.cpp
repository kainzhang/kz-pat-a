//
// Created by Kain Zhang on 2021/12/9.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> seqI(N), seqP(N);
    for (int i = 0; i < N; i++) {
        cin >> seqI[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> seqP[i];
    }
    /*
     * 遍历判断是否为插入排序
     */
    int i = 1;
    while (seqP[i] >= seqP[i - 1] && i < N) {
        i++;
    }
    int idx = i + 1; // 如果是插入排序，未排序部分开始位置
    while (seqP[i] == seqI[i] && i < N) {
        i++;
    }
    if (i == N) {
        cout << "Insertion Sort" << endl;
        sort(seqI.begin(), seqI.begin() + idx);
    } else {
        cout << "Merge Sort" << endl;
        bool flag = true;
        int k = 1;
        while (flag) {
            flag = false;
            for (int j = 0; j < N; j++) {  // seqI, seqP 存在不同元素
                if (seqI[j] != seqP[j]) flag = true;
            }
//            if (seqI[i] != seqP[i]) flag = true;  //  不用遍历，这就能过...
            for (int j = 0; j < N; j += k * 2) {
                int r = j + k * 2;
                if (r > N) {
                    r = N;
                }
                sort(seqI.begin() + j, seqI.begin() + r);
            }
            k *= 2;
        }
    }
    for (int j = 0; j < N; j++) {
        if (j) cout << " ";
        cout << seqI[j];
    }
}