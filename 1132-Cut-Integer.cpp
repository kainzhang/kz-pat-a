//
// Created by Kain Zhang on 2021/12/14.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string Z;
        cin >> Z;
        int len = Z.size();
        int l = stoi(Z.substr(0, len / 2));
        int r = stoi(Z.substr(len / 2));
        if (l * r && stoi(Z) % (l * r) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}