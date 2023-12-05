// https://www.acmicpc.net/problem/11652
// 틀린 이유: 마지막에 한 번 더 비교하기!
#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[1000000];
long long mxNum, mxCnt = 0, num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr+N);

    int cnt = 0;
    mxNum = arr[0];

    for(int i = 0; i < N; i++){
        if(i == 0 || arr[i-1] == arr[i]) cnt++;
        else{
            if(cnt > mxCnt){
                mxCnt = cnt;
                mxNum = arr[i-1];
            }
            cnt = 1;
        }
    }
    if(cnt > mxCnt) mxNum = arr[N-1];
    cout << mxNum;
}