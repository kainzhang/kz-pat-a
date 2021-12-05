//
// Created by Kain Zhang on 2021/12/5.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    string num;
    cin >> num;
    /*
     * 输入范围为 [0, 10^4]
     */
    while (num.size() < 4) {
        num += '0';
    }
    do {
        sort(num.begin(), num.end(), greater<>());
        int num1 = stoi(num);
        sort(num.begin(), num.end());
        int num2 = stoi(num);
        int res = num1 - num2;
        printf("%04d - %04d = %04d\n", num1, num2, res);

        num = to_string(res);
        while (num.size() < 4) {
            num += '0';
        }
    } while (num != "0000" && num != "6174");
}