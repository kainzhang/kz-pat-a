//
// Created by Kain Zhang on 2021/12/10.
//

#include "bits/stdc++.h"
using namespace std;

struct record {
    string pNum;
    int time;
    bool in;
};

// 按车牌号排序，相同则按时间排序，用于为进出记录配对
bool cmp1(const record &a, const record &b) {
    if (a.pNum == b.pNum) {
        return a.time < b.time;
    }
    return a.pNum < b.pNum;
}

bool cmp2(const record &a, const record &b) {
    return a.time < b.time;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    string plate_num, status;
    int hh, mm, ss;
    plate_num.resize(10);
    status.resize(5);
    vector<record> vec;
    for (int i = 0; i < N; i++) {
        scanf("%s %d:%d:%d %s", &plate_num[0], &hh, &mm, &ss, &status[0]);
        record x;
        x.pNum = plate_num;
        x.time = hh * 3600 + mm * 60 + ss;
        if (status[0] == 'i') {
            x.in = true;
        } else {
            x.in = false;
        }
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end(), cmp1);
    vector<record> rec; // 有效 records
    int mxDur = 0; // 最长停车时间
    vector<string> pList; // 停车时间最长的车辆
    map<string, int> mp; // 记录每辆车的总停车时间
    for (int i = 0; i < N - 1; i++) {
        if (vec[i].pNum == vec[i + 1].pNum && vec[i].in && !vec[i + 1].in) {
            mp[vec[i].pNum] += vec[i + 1].time - vec[i].time;
            rec.push_back(vec[i]);
            rec.push_back(vec[i + 1]);
            if (mp[vec[i].pNum] > mxDur) {
                mxDur = mp[vec[i].pNum];
                pList.clear();
                pList.push_back(vec[i].pNum);
            } else if (mp[vec[i].pNum] == mxDur) {
                pList.push_back(vec[i].pNum);
            }
        }
    }
    sort(rec.begin(), rec.end(), cmp2);
    rec.push_back(record{"xxx", INT_MAX, 1});
    int time;
    while (K--) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        time = hh * 3600 + mm * 60 + ss;
        int cnt = 0;
        for (int i = 0; i <= rec.size(); i++) {
            if (rec[i].time > time) {
                printf("%d\n", cnt);
                break;
            } else {
                cnt += (rec[i].in ? 1 : -1);
            }
        }
    }
    sort(pList.begin(), pList.end());
    for (int i = 0; i < pList.size(); i++) {
        if (i) printf(" ");
        printf("%s", pList[i].c_str());
    }
    printf(" %02d:%02d:%02d", mxDur / 3600, mxDur % 3600 / 60, mxDur % 60);
}