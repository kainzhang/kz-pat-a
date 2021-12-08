//
// Created by Kain Zhang on 2021/12/8.
//

#include "bits/stdc++.h"
using namespace std;

struct stu {
    string name, id;
    int grade;
    bool operator < (const stu &x) const {
        return grade > x.grade;
    }
};

int main() {
    int N;
    cin >> N;
    vector<stu> vec(N), li;
    for (int i = 0; i < N; i++) {
        cin >> vec[i].name >> vec[i].id >> vec[i].grade;
    }
    int grade1, grade2;
    cin >> grade1 >> grade2;
    for (stu &it : vec) {
        if (it.grade >= grade1 && it.grade <= grade2) {
            li.push_back(it);
        }
    }
    sort(li.begin(), li.end());
    if (li.empty()) {
        cout << "NONE";
        return 0;
    }
    for (stu &it : li) {
        cout << it.name << " " << it.id << endl;
    }
}