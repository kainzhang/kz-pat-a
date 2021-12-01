//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;

struct node {
    double P, D;
    bool operator < (const node &x) const {
        return D < x.D;
    }
};

int main() {
    int C_max, D, D_avg, N;
    cin >> C_max >> D >> D_avg >> N;
    vector<node> vec(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].P >> vec[i].D;
    }
    vec[N].D = D, vec[N].P = 0;
    sort(vec.begin(), vec.end());

    int ok = 1;
    // 目前行驶距离、总费用、剩余油量还可行驶的距离
    double nowD = 0, totP = 0, leftD = 0;
    if (vec[0].D != 0) {
        ok = 0;
    } else {
        int pre = 0, nxt;
        while (nowD < D) {
            double minP = INT_MAX;
            int flag = 0;
            for (int i = pre + 1; i <= N && vec[i].D <= nowD + C_max * D_avg; i++) {
                if (vec[i].P < vec[pre].P) {
                    // 在可到达范围内找到比上一站便宜的
                    totP += (vec[i].D - nowD - leftD) / D_avg * vec[pre].P;
                    leftD = 0;
                    pre = i;
                    nowD = vec[i].D;
                    flag = 1; // 找到比上一站便宜的
                    break;
                } else if (vec[i].P < minP) {
                    // 没找到，找可到达范围内相对最便宜的
                    minP = vec[i].P;
                    nxt = i;
                }
            }
            if (!flag) {
                // 没找到比上一站便宜的，按相对最便宜的计算
                if (minP != INT_MAX) {
                    totP += vec[pre].P * (C_max - leftD / D_avg);
                    leftD = nowD + C_max * D_avg - vec[nxt].D;
                    nowD = vec[nxt].D;
                    pre = nxt;
                } else {
                    nowD += C_max * D_avg;
                    ok = 0;
                    break;
                }
            }
        }
    }
    if (ok) printf("%.2f", totP);
    else printf("The maximum travel distance = %.2f", nowD);
}