// https://www.acmicpc.net/problem/11650
#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector<pair<int, int>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for(auto p: v) cout << p.first << ' ' << p.second << '\n';
}