// https://www.acmicpc.net/problem/9095
#include <bits/stdc++.h>
using namespace std;

int T, N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--){
        cin >> N;
        int dp[N+1];

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= N; i++){
            dp[i] = dp[i-1];
            if(i-2>=0) dp[i] += dp[i-2];
            if(i-3>=0) dp[i] += dp[i-3];
        }
        cout << dp[N] << '\n';
    }
}