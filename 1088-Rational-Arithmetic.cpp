//
// Created by Kain Zhang on 2021/12/9.
//

#include "bits/stdc++.h"
using namespace std;
using LL = long long;

char sign[] = {'+', '-', '*', '/'};

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

void printRNum(LL num, LL den) {
    LL t = gcd(abs(num), abs(den));
    num /= t, den /= t;
    if (num < 0) printf("(");
    if (den == 1) {
        printf("%lld", num);
    } else if (abs(num) > den) {
        printf("%lld %lld/%lld", num / den, abs(num) % den, den);
    } else {
        printf("%lld/%lld", num, den);
    }
    if (num < 0) printf(")");
}

void printRes(LL num1, LL den1, LL num2, LL den2, char syn) {
    switch (syn) {
        case '-': {
            num2 = -num2;
        }
        case '+': {
            LL num = num1 * den2 + num2 * den1;
            LL den = den1 * den2;
            printRNum(num, den);
            break;
        }
        case '/': {
            if (num2 < 0) {
                num2 = -num2;
                den2 = -den2;
            }
            swap(num2, den2);
            if (den2 == 0) {
                printf("Inf");
                break;
            }
        }
        case '*': {
            LL num = num1 * num2;
            LL den = den1 * den2;
            printRNum(num, den);
            break;
        }
    }
    printf("\n");
}

int main() {
    LL a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    LL t = gcd(abs(a1), abs(b1));
    a1 /= t, b1 /= t;
    t = gcd(abs(a2), abs(b2));
    a2 /= t, b2 /= t;
    for (int i = 0; i < 4; i++) {
        printRNum(a1, b1);
        printf(" %c ", sign[i]);
        printRNum(a2, b2);
        printf(" = ");
        printRes(a1, b1, a2, b2, sign[i]);
    }
}