// https://www.acmicpc.net/problem/1431
#include <bits/stdc++.h>
using namespace std;

int N;
string st;
vector<string> v;

bool cmp (string& a, string& b){
    int lena = a.size(), lenb = b.size();
    int suma = 0, sumb = 0;
    if(lena != lenb) return lena < lenb;    // 길이 비교

    for(auto s: a){
        if(isdigit(s)) suma += s-'0';
    }

    for(auto s: b){
        if(isdigit(s)) sumb += s-'0';
    }

    if(suma!= sumb) return suma < sumb;     // 합 비교

    return a < b;       // 사전순 비교
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> st;
        v.push_back(st);
    }

    sort(v.begin(), v.end(), cmp);

    for(string s: v) cout << s << '\n';
}