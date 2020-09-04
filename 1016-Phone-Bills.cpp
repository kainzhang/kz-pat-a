//
// Created by LOKKA on 2020/9/4.
//

#include <bits/stdc++.h>
using namespace std;

struct Record {
    char name[25];
    int dd, HH, mm, stm, on;
    bool operator < (const Record &x) const {
        if (strcmp(name, x.name) == 0) {
            return stm < x.stm;
        }
        return strcmp(name, x.name) < 0;
    }
};

int toll[25], N, MM;
vector<Record> vec(1005);

double getCharge(Record a, Record b) {
    double res = 0;
    while (a.dd != b.dd || a.HH != b.HH || a.mm != b.mm) {
        if (a.dd == b.dd && a.HH == b.HH) {
            res += toll[a.HH] * (b.mm - a.mm);
            a.mm = b.mm;
        } else {
            res += toll[a.HH] * (60 - a.mm);
            a.mm = 0;
            a.HH++;
            if (a.HH == 24) {
                a.HH = 0;
                a.dd++;
            }
        }
    }
    return res / 100;
}

int main() {
    for (int i = 0; i < 24; i++) {
        scanf("%d", &toll[i]);
    }
    scanf("%d", &N);
    char sign[10];
    for (int i = 0; i < N; i++) {
        scanf("%s %d:%d:%d:%d %s", vec[i].name, &MM, &vec[i].dd, &vec[i].HH, &vec[i].mm, sign);
        vec[i].stm = (vec[i].dd * 24 + vec[i].HH) * 60 + vec[i].mm;
        if (sign[1] == 'n') vec[i].on = 1;
        else vec[i].on = 0;
    }
    sort(vec.begin(), vec.begin() + N);
    double totamt = 0;
    int flag = 0;
    for (int i = 0; i < N - 1; i++) {
        if (strcmp(vec[i].name, vec[i + 1].name) == 0 && vec[i].on && !vec[i + 1].on) {
            if (!flag) {
                printf("%s %02d\n", vec[i].name, MM);
                flag = 1;
            }
            double chg = getCharge(vec[i], vec[i + 1]);
            printf("%02d:%02d:%02d ", vec[i].dd, vec[i].HH, vec[i].mm);
            printf("%02d:%02d:%02d ", vec[i + 1].dd, vec[i + 1].HH, vec[i + 1].mm);
            printf("%d $%.2f\n", vec[i + 1].stm - vec[i].stm, chg);
            totamt += chg;
        } else if (strcmp(vec[i].name, vec[i + 1].name)) {
            if (flag) {
                printf("Total amount: $%.2f\n", totamt);
            }
            flag = totamt = 0;
        }
    }
    if (flag) {
        printf("Total amount: $%.2f\n", totamt);
    }
}