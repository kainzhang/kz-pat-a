//
// Created by Kain Zhang on 2021/12/10.
//

#include "bits/stdc++.h"
using namespace std;

string fir[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string sec[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void printEar2Mar(string str) {
    int x = stoi(str);
    if (x / 13) {
        cout << sec[x / 13];
        if (x % 13) {
            cout << " " << fir[x % 13];
        }
    } else {
        cout << fir[x % 13];
    }
    cout << endl;
}

void printMar2Ear(string str) {
    int idx = 0;
    string num[2];
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            idx++;
            continue;
        }
        num[idx].push_back(str[i]);
    }
    int f = 0, s = 0;
    for (int i = 0; i < 13; i++) {
        if (fir[i] == num[idx]) {
            f = i;
        }
        if (sec[i] == num[0]) {
            s = i;
        }
    }
    cout << s * 13 + f << endl;
}

int main() {
    int N;
    cin >> N;
    getchar();
    for (int i = 0; i < N; i++) {
        string str;
        getline(cin, str);
        if (isdigit(str[0])) {
            printEar2Mar(str);
        } else {
            printMar2Ear(str);
        }
    }
}