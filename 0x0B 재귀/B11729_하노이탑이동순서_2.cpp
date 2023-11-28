// https://www.acmicpc.net/problem/11729
#include <bits/stdc++.h>
using namespace std;

int N;
queue<pair<int, int>> Q;

int func(int n, int s, int e, int m){
    if(n == 1){     // 1개인 경우 1 리턴
        Q.push({s, e});
        return 1;
    }
    int cnt = 0;                           // 초기값 설정
    cnt += func(n-1, s, m, e);  // n-1개 시작 -> 보조 기둥으로 이동
    cnt++;
    Q.push({s, e});             // n-1개 보조 -> 도착 기둥으로 이동
    cnt += func(n-1, m, e, s);
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    cout << func(N, 1, 3, 2) << '\n';

    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        cout << cur.first << ' ' << cur.second << '\n';
    }
}