//
// Created by LOKKA on 2020/9/4.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 2005;

struct Node {
    string id;
    int C, M, E, A, rC, rM, rE, rA;
};

vector<Node> vec(mxN);
unordered_map<string, int> mp;
int N, M;

bool cmpC(const Node &a, const Node &b) {
    return a.C > b.C;
}
bool cmpM(const Node &a, const Node &b) {
    return a.M > b.M;
}
bool cmpE(const Node &a, const Node &b) {
    return a.E > b.E;
}
bool cmpA(const Node &a, const Node &b) {
    return a.A > b.A;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> vec[i].id >> vec[i].C >> vec[i].M >> vec[i].E;
        vec[i].A = vec[i].C + vec[i].M + vec[i].E;
    }
    sort(vec.begin() + 1, vec.begin() + N + 1, cmpC);
    for (int i = 1; i <= N; i++) {
        vec[i].rC = (vec[i].C == vec[i - 1].C) ? vec[i - 1].rC : i;
    }
    sort(vec.begin() + 1, vec.begin() + N + 1, cmpM);
    for (int i = 1; i <= N; i++) {
        vec[i].rM = (vec[i].M == vec[i - 1].M) ? vec[i - 1].rM : i;
    }
    sort(vec.begin() + 1, vec.begin() + N + 1, cmpE);
    for (int i = 1; i <= N; i++) {
        vec[i].rE = (vec[i].E == vec[i - 1].E) ? vec[i - 1].rE : i;
    }
    sort(vec.begin() + 1, vec.begin() + N + 1, cmpA);
    for (int i = 1; i <= N; i++) {
        vec[i].rA = (vec[i].A == vec[i - 1].A) ? vec[i - 1].rA : i;
        mp[vec[i].id] = i;
    }

    while (M--) {
        string id;
        cin >> id;
        if (mp[id]) {
            int i = mp[id];
            int bstR = vec[i].rA;
            char bstS = 'A';
            if (vec[i].rC < bstR) {
                bstR = vec[i].rC;
                bstS = 'C';
            }
            if (vec[i].rM < bstR) {
                bstR = vec[i].rM;
                bstS = 'M';
            }
            if (vec[i].rE < bstR) {
                bstR = vec[i].rE;
                bstS = 'E';
            }
            cout << bstR << " " << bstS << endl;
        } else {
            cout << "N/A" << endl;
        }
    }
}