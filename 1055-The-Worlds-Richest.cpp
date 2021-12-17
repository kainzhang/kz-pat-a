//
// Created by LOKKA on 2021/12/17.
//

#include "bits/stdc++.h"
using namespace std;

struct node {
    string name;
    int age, net_worth;
    bool operator < (const node& x) const {
         if (net_worth == x.net_worth) {
             if (age == x.age) {
                 return name < x.name;
             }
             return age < x.age;
         }
         return net_worth > x.net_worth;
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    vector<node> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].name >> vec[i].age >> vec[i].net_worth;
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= K; i++) {
        int M, Amin, Amax, flag = 0;
        cin >> M >> Amin >> Amax;
        printf("Case #%d:\n", i);
        for (int j = 0; j < N; j++) {
            if (vec[j].age >= Amin && vec[j].age <= Amax) {
                printf("%s %d %d\n", vec[j].name.c_str(), vec[j].age, vec[j].net_worth);
                M--;
                flag++;
            }
            if (!M) break;
        }
        if (!flag) {
            printf("None\n");
        }
    }
}