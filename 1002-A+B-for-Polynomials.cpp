#include <bits/stdc++.h>
using namespace std;

map<int, double> ply;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 2, K, N;
    double a;
    while (T--) {
        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> N >> a;
            ply[N] += a;
            if (ply[N] == 0)
                ply.erase(N);
        }
    }
    printf("%d", ply.size());
    for (auto i = ply.rbegin(); i != ply.rend(); i++) {
        printf(" %d %.1f", i->first, i->second);
    }
}
