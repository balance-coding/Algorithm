// https://www.acmicpc.net/problem/7795
#include <bits/stdc++.h>
using namespace std;

int T, N, M, arrA[20000], arrB[20000], ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--){
        cin >> N >> M;
        ans = 0;

        for(int i = 0; i < N; i++) cin >> arrA[i];
        for(int i = 0; i < M; i++) cin >> arrB[i];

        sort(arrA, arrA+N);
        sort(arrB, arrB+M);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(arrA[i] <= arrB[j]) break;
                else ans++;
            }
        }
        cout << ans << '\n';
    }
}