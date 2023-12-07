// https://www.acmicpc.net/problem/1181
#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<string> v;

bool cmp(const string &a, const string &b){
    if(a.length() != b.length()) return a.length() < b.length();
    return a < b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while(N--){
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto word: v){
        cout << word << '\n';
    }
}