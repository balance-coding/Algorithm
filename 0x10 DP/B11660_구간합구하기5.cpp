// https://www.acmicpc.net/problem/11660
#include <bits/stdc++.h>
using namespace std;

int N, M, a1, a2, b1, b2;
int arr[1025][1025], dp[1025][1025];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }

    while(M--){
        cin >> a1 >> b1 >> a2 >> b2;
        cout << dp[a2][b2] + dp[a1-1][b1-1] - dp[a1-1][b2] - dp[a2][b1-1] << '\n';
    }


}