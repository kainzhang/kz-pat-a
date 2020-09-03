//
// Created by LOKKA on 2020/9/3.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int exp;
    double coe;
};

map<int, double> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int KA, KB;
    cin >> KA;
    vector<Node> A(KA);
    for (int i = 0; i < KA; i++) {
        cin >> A[i].exp >> A[i].coe;
    }
    cin >> KB;
    vector<Node> B(KB);
    for (int i = 0; i < KB; i++) {
        cin >> B[i].exp >> B[i].coe;
    }
    for (Node &i : A) {
        for (Node &j : B) {
            int EXP = i.exp + j.exp;
            mp[EXP] += i.coe * j.coe;
            if (mp[EXP] == 0) mp.erase(EXP);
        }
    }
    printf("%d", mp.size());
    for (auto i = mp.rbegin(); i != mp.rend(); i++) {
        printf(" %d %.1f", i->first, i->second);
    }
}