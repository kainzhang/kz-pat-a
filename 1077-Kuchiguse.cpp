//
// Created by Kain Zhang on 2021/12/8.
//

#include "bits/stdc++.h"
using namespace std;

vector<string> vec;

int main() {
    int N;
    cin >> N;
    getchar();
    string str;
    for (int i = 0; i < N; i++) {
        getline(cin, str);
        reverse(str.begin(), str.end());
        vec.push_back(str);
    }
    string ans = "";
    for (int i = 0; i < vec[0].size(); i++) {
        char c = vec[0][i];
        for (int j = 1; j < N; j++) {
            if (vec[j][i] != c) {
                goto fin;
            }
        }
        ans = c + ans;
    }
    fin:
    cout << (ans == "" ? "nai" : ans);
}