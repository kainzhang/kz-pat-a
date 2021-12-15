//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;
const int mxK = 1e3 + 5;

// 初始结束服务时间为8点，即480
struct window {
    // 窗口结束服务的时间，结束队首顾客服务的时间（pop队首顾客
    int endT = 480, popT;
    queue<int> que;
};

vector<window> win(25);
// 每个顾客的服务时间和服务完成时间
vector<int> pcsT(mxK), finT(mxK);

int main() {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < K; i++) {
        cin >> pcsT[i];
    }

    // 处理在黄线内排队的顾客
    int s = 0;
    for (int i = 0; i < min(N * M, K); i++) {
        win[i % N].que.push(i);
        win[i % N].endT += pcsT[i];
        // 每个窗口接待第一个顾客的服务时间
        if (i < N) {
            win[i].popT = pcsT[i];
        }
        finT[i] = win[i % N].endT;
        s++;
    }
    // 处理黄线外剩余顾客
    for (int i = s; i < K; i++) {
        int idx = -1, MIN = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (win[j].popT < MIN) {
                idx = j;
                MIN = win[j].popT;
            }
        }
        window& w = win[idx];
        w.que.pop();
        w.que.push(i);
        w.endT += pcsT[i]; // 窗口结束当前所有服务的时间
        finT[i] = w.endT; // 队末顾客结束服务的时间
        w.popT += pcsT[w.que.front()]; // 队首顾客结束服务时间
    }

    int num;
    while (Q--) {
        cin >> num;
        // 开始服务时间晚于17点，则sorry
        if (finT[num - 1] - pcsT[num - 1] >= 1020) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", finT[num - 1] / 60, finT[num - 1] % 60);
        }
    }
}