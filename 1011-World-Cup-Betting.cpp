//
// Created by LOKKA on 2020/9/4.
//

#include <bits/stdc++.h>
using namespace std;

char ch[] = {'W', 'T', 'L'};

int main() {
    double res = 1;
    for (int i = 0; i < 3; i++) {
        double tmp, MAX = DBL_MIN;
        int MAX_j;
        for (int j = 0; j < 3; j++) {
            cin >> tmp;
            if (tmp > MAX) {
                MAX = tmp;
                MAX_j = j;
            }
        }
        res *= MAX;
        printf("%c ", ch[MAX_j]);
    }
    printf("%.2f", (res * 0.65 - 1) * 2);
}