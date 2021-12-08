//
// Created by Kain Zhang on 2021/12/8.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    string in, out;
    getline(cin, in);
    getline(cin, out);
    unordered_map<char, int> mp;
    for (int i = 0, j = 0; i < in.size(); i++) {
        in[i] = toupper(in[i]);
        out[j] = toupper(out[j]);
        if (in[i] == out[j]) {
            j++;
        } else {
            if (mp[in[i]]) {
                continue;
            }
            cout << in[i];
            mp[in[i]]++;
        }
    }
}