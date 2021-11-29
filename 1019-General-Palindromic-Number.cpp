//
// Created by Kain Zhang on 2021/11/29.
//

#include "bits/stdc++.h"
using namespace std;

vector<int> nums;

// 获取对应进制各位数字
void getRadixVec(int x, int b) {
    while (x) {
        nums.push_back(x % b);
        x /= b;
    }
}

int main() {
    int N, b;
    cin >> N >> b;
    getRadixVec(N, b);
    int len = nums.size(), flag = 1;
    for (int i = 0; i <= len / 2; i++) {
        if (nums[i] != nums[len - i - 1]) {
            flag = 0;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    for (int i = len - 1; i >= 0; i--) {
        cout << nums[i];
        if (i) cout << " ";
    }
}