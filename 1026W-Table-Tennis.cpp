//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e5 + 5;

struct player {
    // 到达时间，游玩时间，开始服务时间
    int arvT, plyT, srvT, vip;
};

struct table {
    int time = 28800, cnt = 0, vip = 0;
};

vector<int> vis(mxN);

// 按到达时间排序
bool cmp1(const player& a, const player& b) {
    return a.arvT < b.arvT;
}

// 按开始服务时间排序
bool cmp2(const player& a, const player& b) {
    return a.srvT < b.srvT;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<player> vec(N);
    for (int i = 0; i < N; i++) {
        int HH, MM, SS;
        scanf("%d:%d:%d %d %d", &HH, &MM, &SS, &vec[i].plyT, &vec[i].vip);
        vec[i].arvT = (HH * 60 + MM) * 60 + SS;
        if (vec[i].plyT > 120) { // PLAY 最多两小时
            vec[i].plyT = 120;
        }
        vec[i].plyT *= 60;
    }
    sort(vec.begin(), vec.end(), cmp1);
    int K, M;
    scanf("%d %d", &K, &M);
    vector<table> tab(K);
    for (int i = 0; i < M; i++) {
        int tmp;
        scanf("%d", &tmp);
        tab[tmp - 1].vip = 1;
    }
    int vip_cnt = 0;
    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        int idx = -1, vip_idx = -1, MIN = INT_MAX, vip_MIN = INT_MAX;
        for (int j = 0; j < K; j++) {
            if (tab[j].time < MIN) {
                idx = j;
                MIN = tab[j].time;
            }
            if (tab[j].vip && tab[j].time < vip_MIN) {
                vip_idx = j;
                vip_MIN = tab[j].time;
            }
        }

        int pid = i;
        if (vec[pid].vip && tab[vip_idx].time <= vec[pid].arvT) {
            idx = vip_idx;
        }
        if (tab[idx].vip) {
            for (int k = i; k < N; k++) {
                if (!vis[k] && vec[k].vip && vec[k].arvT <= tab[idx].time) {
                    pid = k;
                    i--;
                    break;
                }
            }
        }

        if (vec[pid].arvT >= tab[idx].time) {
            vec[pid].srvT = vec[pid].arvT;
            tab[idx].time = vec[pid].arvT + vec[pid].plyT;
        } else {
            vec[pid].srvT = tab[idx].time;
            tab[idx].time += vec[pid].plyT;
        }
        if (vec[pid].srvT < 75600) {
            tab[idx].cnt++;
        }
        vis[pid]++;
    }
    sort(vec.begin(), vec.end(), cmp2);
    for (int i = 0; i < N; i++) {
        if (vec[i].srvT >= 75600) continue;
        printf("%02d:%02d:%02d ", vec[i].arvT / 3600, vec[i].arvT % 3600 / 60, vec[i].arvT % 60);
        printf("%02d:%02d:%02d ", vec[i].srvT / 3600, vec[i].srvT % 3600 / 60, vec[i].srvT % 60);
        int witT = round((vec[i].srvT - vec[i].arvT) * 1.0 / 60);
        printf("%d\n", witT);
    }
    for (int i = 0; i < K; i++) {
        if (i) printf(" ");
        printf("%d", tab[i].cnt);
    }
}