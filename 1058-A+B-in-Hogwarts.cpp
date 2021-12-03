//
// Created by Kain Zhang on 2021/12/3.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    int AG, AS, AK, BG, BS, BK;
    scanf("%d.%d.%d", &AG, &AS, &AK);
    scanf("%d.%d.%d", &BG, &BS, &BK);
    AK += BK;
    AS += AK / 29;
    AK %= 29;
    AS += BS;
    AG += AS / 17;
    AS %= 17;
    AG += BG;
    printf("%d.%d.%d", AG, AS, AK);
}