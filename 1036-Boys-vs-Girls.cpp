//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;

struct stu {
    string name, id;
    char gender;
    int grade;
    bool operator < (const stu &x) const {
        return grade > x.grade;
    }
};

int main() {
    int N;
    cin >> N;
    vector<stu> vecF, vecM;
    for (int i= 0; i < N; i++) {
        stu x;
        cin >> x.name >> x.gender >> x.id >> x.grade;
        if (x.gender == 'F') {
            vecF.push_back(x);
        } else {
            vecM.push_back(x);
        }
    }
    int flag = 1, hi, lo;
    if (vecF.empty()) {
        cout << "Absent" << endl;
        flag = 0;
    } else {
        sort(vecF.begin(), vecF.end());
        cout << vecF[0].name << " " << vecF[0].id << endl;
        hi = vecF[0].grade;
    }
    if (vecM.empty()) {
        cout << "Absent" << endl;
        flag = 0;
    } else {
        sort(vecM.begin(), vecM.end());
        cout << vecM[vecM.size() - 1].name << " " << vecM[vecM.size() - 1].id << endl;
        lo = vecM[vecM.size() - 1].grade;
    }
    if (!flag) {
        cout << "NA";
    } else {
        cout << hi - lo;
    }
}