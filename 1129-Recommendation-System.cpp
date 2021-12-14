//
// Created by Kain Zhang on 2021/12/14.
//

#include "bits/stdc++.h"
using namespace std;

struct node {
    int idx, cnt;
    bool operator < (const node &x) const {
        if (cnt == x.cnt) {
            return idx < x.idx;
        }
        return cnt > x.cnt;
    }
};

set<node> st;
unordered_map<int, int> mp;

int main() {
    int N, K;
    cin >> N >> K;
    int flag = 0;
    while(N--) {
        int x;
        cin >> x;
        if (!st.empty()) {
            cout << x << ":";
            int i = 0;
            for (auto &it : st) {
                if (i++ == K) {
                    break;
                }
                cout << " " << it.idx;
            }
            cout << endl;
        }
        auto it = st.find(node{x, mp[x]});
        if (it != st.end()) {
            st.erase(it);
        }
        mp[x]++;
        st.insert(node{x, mp[x]});
    }
}