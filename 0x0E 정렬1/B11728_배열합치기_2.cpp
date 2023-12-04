// https://www.acmicpc.net/problem/11728
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arrA[1000000], arrB[1000000];
int ans[2000000];
int startA = 0, startB = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> arrA[i];
    for(int i = 0; i < M; i++) cin >> arrB[i];

//    while(true){
//        if(startA == N || startB == M){
//            for(int i = startA; i < N; i++) ans[last++] = arrA[i];
//            for(int i = startB; i < M; i++) ans[last++] = arrB[i];
//            break;
//        }
//
//        if(arrA[startA] >= arrB[startB]){
//            ans[last++] = arrB[startB++];
//        }
//        else {
//            ans[last++] = arrA[startA++];
//        }
//    }
    for(int i = 0; i < N+M; i++){
        if(startA == N) ans[i] = arrB[startB++];
        else if(startB == M) ans[i] = arrA[startA++];
        else if(arrA[startA] >= arrB[startB]) ans[i] = arrB[startB++];
        else ans[i] = arrA[startA++];
    }

    for(int i = 0; i < N+M; i++){
        cout << ans[i] << ' ';
    }
}