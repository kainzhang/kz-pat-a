//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;

struct testee {
    string regis_num;
    int score, fin_rank, loc_num, loc_rank;

    bool operator < (const testee &x) const {
        if (score == x.score) {
            return regis_num < x.regis_num;
        }
        return score > x.score;
    }
};

vector<testee> vec;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K, b = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> K;
        for (int j = 0; j < K; j++) {
            testee x;
            cin >> x.regis_num >> x.score;
            x.loc_num = i;
            vec.push_back(x);
        }

        // get location rank
        sort(vec.begin() + b, vec.begin() + b + K);
        for (int j = b, rnk = 1; j < b + K; j++, rnk++) {
            if (j > b && vec[j].score == vec[j - 1].score) {
                vec[j].loc_rank = vec[j - 1].loc_rank;
            } else {
                vec[j].loc_rank = rnk;
            }
        }
        b += K;
    }

    // get final rank
    sort(vec.begin(), vec.end());
    int len = vec.size();
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        if (i > 0 && vec[i].score == vec[i - 1].score) {
            vec[i].fin_rank = vec[i - 1].fin_rank;
        } else {
            vec[i].fin_rank = i + 1;
        }
        cout << vec[i].regis_num << " " << vec[i].fin_rank << " " << vec[i].loc_num << " " << vec[i].loc_rank << endl;
    }
}