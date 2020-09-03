//
// Created by LOKKA on 2020/9/3.
//

#include <bits/stdc++.h>
using namespace std;

struct Record {
    int hh, mm, ss;
};

struct Node {
    string id;
    Record in, out;
};

bool cmpIn(const Node &a, const Node &b) {
    return (a.in.hh * 3600 + a.in.mm * 60 + a.in.ss) < (b.in.hh * 3600 + b.in.mm * 60 + b.in.ss);
}

bool cmpOut(const Node &a, const Node &b) {
    return (a.out.hh * 3600 + a.out.mm * 60 + a.out.ss) > (b.out.hh * 3600 + b.out.mm * 60 + b.out.ss);
}

int main() {
    int M;
    cin >> M;
    vector<Node> vec;
    while (M--) {
        Node tmp;
        cin >> tmp.id;
        scanf("%d:%d:%d %d:%d:%d",
            &tmp.in.hh, &tmp.in.mm, &tmp.in.ss,
            &tmp.out.hh, &tmp.out.mm, &tmp.out.ss
        );
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), cmpIn);
    cout << vec[0].id;
    sort(vec.begin(), vec.end(), cmpOut);
    cout << " " << vec[0].id;
}