//
// Created by Kain Zhang on 2021/12/3.
//

#include "bits/stdc++.h"
using namespace std;

string wk[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int len = min(str1.size(), str2.size()), cnt = 0;
    for (int i = 0; i <len; i++) {
        if (!cnt) {
            if (isupper(str1[i]) && str1[i] == str2[i] && str1[i] <= 'G') {
                cnt++;
                printf("%s", wk[str1[i] - 'A'].c_str());
            }
        } else if (str1[i] == str2[i]) {
            if (isupper(str1[i]) && str1[i] <= 'N') {
                printf(" %d", str1[i] - 'A' + 10);
                break;
            } else if (isdigit(str1[i])) {
                printf(" %02d", str1[i] - '0');
                break;
            }
        }
    }

    getline(cin, str1);
    getline(cin, str2);
    len = min(str1.size(), str2.size());
    for (int i = 0; i < len; i++) {
        if (isalpha(str1[i]) && str1[i] == str2[i]) {
            printf(":%02d", i);
            break;
        }
    }
}