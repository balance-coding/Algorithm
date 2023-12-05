// https://www.acmicpc.net/problem/10814
#include <bits/stdc++.h>
using namespace std;

int N, age;
string name;
vector<pair<int, string>> v;

bool cmp(const pair<int, string>& a, const pair<int, string>& b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> age >> name;
        v.push_back({age, name});
    }

    stable_sort(v.begin(), v.end(), cmp);

    for(auto p: v){
        cout << p.first << ' ' << p.second << '\n';
    }
}