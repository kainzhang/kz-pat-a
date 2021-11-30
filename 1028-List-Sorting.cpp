//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;

struct stu {
    string id, name;
    int grade;
};

bool cmp1 (const stu &a, const stu &b) {
    return a.id < b.id;
}

bool cmp2 (const stu &a, const stu &b) {
    if (a.name == b.name) {
        return cmp1(a, b);
    }
    return a.name < b.name;
}

bool cmp3 (const stu &a, const stu &b) {
    if (a.grade == b.grade) {
        return cmp1(a, b);
    }
    return a.grade < b.grade;
}

vector<stu> vec;

int main() {
    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        stu x;
        cin >> x.id >> x.name >> x.grade;
        vec.push_back(x);
    }
    switch (C) {
        case 1: sort(vec.begin(), vec.end(), cmp1); break;
        case 2: sort(vec.begin(), vec.end(), cmp2); break;
        case 3: sort(vec.begin(), vec.end(), cmp3); break;
    }
    for (auto &i : vec) {
        cout << i.id << " " << i.name << " " << i.grade << endl;
    }
}