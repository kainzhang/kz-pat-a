//
// Created by LOKKA on 2020/9/3.
//

#include <bits/stdc++.h>
using namespace std;

string num[] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

int flag = 0;
void print(int sum) {
    int x = sum % 10;
    sum /= 10;
    if (sum) print(sum);
    if (flag) cout << " ";
    cout << num[x];
    flag = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    int sum = 0;
    for (char &c : str) {
        sum += c - '0';
    }
    print(sum);
}