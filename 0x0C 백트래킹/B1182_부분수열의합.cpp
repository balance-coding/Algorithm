// https://www.acmicpc.net/problem/1182
#include <bits/stdc++.h>
using namespace std;

int N, S;
int ans = 0;
int arr[20];

void func(int cur, int sum){
    if(cur == N){
        if(sum == S) ans++;
        return;
    }
    func(cur+1, sum);
    func(cur+1, sum+arr[cur]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> arr[i];

    func(0, 0);
    if(S==0) ans--;
    cout << ans;
}