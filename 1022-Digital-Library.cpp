//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;

unordered_map<string, vector<string>> title, auth, kwds, pub, yr;

void printAns(unordered_map<string, vector<string>> &mp, string str) {
    if (mp[str].empty()) {
        cout << "Not Found" << endl;
    }
    set<string> res(mp[str].begin(), mp[str].end());
    for (auto &i : res) {
        cout << i << endl;
    }
}

int main() {
    int N;
    cin >> N;
    getchar();
    string id, tt, aa, kk, pp, yy;
    while (N--) {
        getline(cin, id);
        getline(cin, tt);
        title[tt].push_back(id);
        getline(cin, aa);
        auth[aa].push_back(id);
        while (cin >> kk) {
            char t = getchar();
            kwds[kk].push_back(id);
            if (t == '\n') break;
        }
        getline(cin, pp);
        pub[pp].push_back(id);
        getline(cin, yy);
        yr[yy].push_back(id);
    }
    int M;
    cin >> M;
    getchar();
    while (M--) {
        int sign;
        string str;
        getline(cin, str);
        sign = str[0] - '0';
        str = str.substr(3);
        cout << sign << ": " << str << endl;
        switch (sign) {
            case 1: printAns(title, str); break;
            case 2: printAns(auth, str); break;
            case 3: printAns(kwds, str); break;
            case 4: printAns(pub, str); break;
            case 5: printAns(yr, str); break;
        }
    }
}