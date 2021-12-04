//
// Created by Kain Zhang on 2021/12/4.
//

#include "bits/stdc++.h"
using namespace std;

struct man {
    string id;
    int vg, tg, rk;
    bool operator < (const man &x) const {
        if (rk == x.rk) {
            if (vg + tg == x.vg + x.tg) {
                if (vg == x.vg) {
                    return id < x.id;
                }
                return vg > x.vg;
            }
            return vg + tg > x.vg + x.tg;
        }
        return rk < x.rk;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, L, H;
    cin >> N >> L >> H;
    vector<man> men;
    for (int i = 0; i < N; i++) {
        man x;
        cin >> x.id >> x.vg >> x.tg;
        if (x.vg >= L && x.tg >= L) {
            if (x.vg >= H && x.tg >= H) {
                x.rk = 1;
            } else if (x.vg >= H && x.tg < H) {
                x.rk = 2;
            } else if (x.vg < H && x.tg < H && x.vg >= x.tg) {
                x.rk = 3;
            } else {
                x.rk = 4;
            }
            men.push_back(x);
        }
    }
    cout << men.size() << endl;
    sort(men.begin(), men.end());
    for (man &it : men) {
        cout << it.id << " " << it.vg << " " << it.tg << endl;
    }
}