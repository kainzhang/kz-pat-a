//
// Created by Kain Zhang on 2021/12/2.
//

#include "bits/stdc++.h"
using namespace std;
const int mxN = 1e3 + 5;

vector<int> vec(mxN), post;

bool isM = false;
void getPost(int L, int R) {
    int i = L + 1, j = R;
    if (!isM) {
        while (i <= R && vec[L] > vec[i]) {
            i++;
        }
        while (j > L && vec[L] <= vec[j]) {
            j--;
        }
    } else {
        while (i <= R && vec[L] <= vec[i]) {
            i++;
        }
        while (j > L && vec[L] > vec[j]) {
            j--;
        }
    }
    if (i - j != 1) return;
    getPost(L + 1, j);
    getPost(i, R);
    post.push_back(vec[L]);
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    getPost(0, N - 1);
    if (post.size() != N) {
        isM = true;
        post.clear();
        getPost(0, N - 1);
    }
    if (post.size() == N){
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
            if (i) cout << " ";
            cout << post[i];
        }
    } else {
        cout << "NO";
    }
}