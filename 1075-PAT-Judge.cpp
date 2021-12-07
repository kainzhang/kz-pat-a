//
// Created by Kain Zhang on 2021/12/7.
//

#include "bits/stdc++.h"
using namespace std;

struct usr {
    string id;
    int tot_score, score[6], status[6], perfect;
    bool operator < (const usr &x) const {
        if (tot_score == x.tot_score) {
            if (perfect == x.perfect) {
                return id < x.id;
            }
            return perfect > x.perfect;
        }
        return tot_score > x.tot_score;
    }
};

unordered_map<string, usr> mp;

int main() {
    int N, K, M, p[6];
    cin >> N >> K >> M;
    for (int i = 1; i <= K; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < M; i++) {
        string u_id;
        int prob_id, part_score;
        cin >> u_id >> prob_id >> part_score;
        mp[u_id].id = u_id;
        mp[u_id].score[prob_id] = max(mp[u_id].score[prob_id], part_score);
        /*
         * 注意已通过编译的题，但二次提交未通过编译时的处理
         */
        if (part_score == -1 && mp[u_id].status[prob_id] != 1) {
            mp[u_id].status[prob_id] = -1; // 未通过编译
        } else {
            mp[u_id].status[prob_id] = 1;  // 通过编译
        }
    }
    vector<usr> vec;
    for (auto &it : mp) {
        int flag = 0;
        for (int i = 1; i <= K; i++) {
            it.second.tot_score += it.second.score[i];
            if (it.second.score[i] == p[i]) {
                it.second.perfect++;
            }
            if (it.second.status[i] == 1) {
                flag++;
            }
        }
        if (flag) {
            vec.push_back(it.second);
        }
    }
    sort(vec.begin(), vec.end());
    int rank = 1;
    for (int i = 0; i < vec.size(); i++) {
        if (i && vec[i].tot_score < vec[i - 1].tot_score) {
            rank = i + 1;
        }
        cout << rank << " " << vec[i].id << " " << vec[i].tot_score;
        for (int j = 1; j <= K; j++) {
            switch (vec[i].status[j]) {
                case -1: cout << " 0"; break;
                case 1: cout << " " << vec[i].score[j]; break;
                case 0: cout << " -"; break;
            }
        }
        cout << endl;
    }
}