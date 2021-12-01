//
// Created by Kain Zhang on 2021/12/1.
//

#include "bits/stdc++.h"
using namespace std;

struct usr {
    string name, pwd;
};

int main() {
    int N, M = 0;
    cin >> N;
    vector<usr> ans;
    for (int i = 0; i < N; i++) {
        usr u;
        cin >> u.name >> u.pwd;
        int len = u.pwd.size(), flag = 0;
        for (int i = 0; i < len; i++) {
            switch (u.pwd[i]) {
                case '1': u.pwd[i] = '@'; flag++; break;
                case '0': u.pwd[i] = '%'; flag++; break;
                case 'l': u.pwd[i] = 'L'; flag++; break;
                case 'O': u.pwd[i] = 'o'; flag++; break;
            }
        }
        if (flag) {
            ans.push_back(u);
            M++;
        }
    }
    if (!M) {
        if (N == 1) {
            cout << "There is " << N <<" account and no account is modified";
        } else {
            cout << "There are " << N <<" accounts and no account is modified";
        }
    } else {
        cout << M << endl;
        for (auto &i : ans) {
            cout << i.name << " " << i.pwd << endl;
        }
    }
}