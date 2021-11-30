//
// Created by Kain Zhang on 2021/11/30.
//

#include "bits/stdc++.h"
using namespace std;

string ch = "0123456789ABC";

void printVal(int x) {
    cout << ch[x / 13] << ch[x % 13];
}

int main() {
    int R, G, B;
    cin >> R >> G >> B;
    cout << "#";
    printVal(R);
    printVal(G);
    printVal(B);
}