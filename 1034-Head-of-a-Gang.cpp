//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;

unordered_map<string, vector<string> > G;
unordered_map<string, int> w, vis;

string hd_name;
int mx_time, cnt, tot_time;
void dfs(string name) {
    int time = w[name];
    if (time > mx_time) {
        mx_time = time;
        hd_name = name;
    }
    tot_time += time;
    cnt++;
    vis[name]++;
    for (auto &i : G[name]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    string Name1, Name2;
    int Time;
    for (int i = 0; i < N; i++) {
        cin >> Name1 >> Name2 >> Time;
        G[Name1].push_back(Name2);
        G[Name2].push_back(Name1);
        w[Name1] += Time;
        w[Name2] += Time;
    }
    map<string, int> ans;
    for (auto &i : w) {
        if (!vis[i.first]) {
            cnt = mx_time = tot_time = 0;
            dfs(i.first);
            if (tot_time / 2 > K && cnt > 2) {
                ans[hd_name] = cnt;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i.first << " " << i.second << endl;
    }
}