// https://www.acmicpc.net/problem/10814
// 무조건 stable_sort를 사용해야된다!
#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    pair<int, string> p[N];

    for(auto& s: p) cin >> s.first >> s.second;

    stable_sort(p, p+N, [&](pair<int, string> a, pair<int, string> b){
        return a.first < b.first;
    });
    for(auto s: p) cout << s.first << ' ' << s.second << '\n';
}