// https://www.acmicpc.net/problem/11047
#include <bits/stdc++.h>
using namespace std;

int N, K;
int coins[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    int ans = 0;

    for(int i = 0; i < N; i++){
        cin >> coins[i];
    }

    for(int i = N-1; i >= 0; i--){
        ans += K / coins[i];
        K %= coins[i];
    }
    cout << ans;
}