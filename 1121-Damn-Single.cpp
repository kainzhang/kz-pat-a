//
// Created by Kain Zhang on 2021/12/12.
//

#include "bits/stdc++.h"
using namespace std;

/*
 * 测试点3参加party的单身狗ID有重复，同一ID不能重复输出
 */

int main() {
    int N, M;
    cin >> N;
    unordered_map<string, string> cp;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        cp[a] = b;
        cp[b] = a;
    }
    cin >> M;
    map<string, int> gue;
    while (M--) {
        string id;
        cin >> id;
        gue[id]++;
    }
    vector<string> sgl;
    for (auto &it : gue) {
        if (cp[it.first].empty() || !gue[cp[it.first]]) {
            sgl.push_back(it.first);
        }
    }
    cout << sgl.size() << endl;
    for (int i = 0; i < sgl.size(); i++) {
        if (i) cout << " ";
        cout << sgl[i];
    }
}