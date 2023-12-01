// https://www.acmicpc.net/problem/10870
#include <bits/stdc++.h>
using namespace std;

int N;
int arr[21];

void fibo(int i){
    arr[i] = arr[i-1] + arr[i-2];
    if(i == N){
        return;
    }else{
        fibo(i+1);
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    arr[0] = 0;
    arr[1] = 1;

    if(N < 2) cout << arr[N];
    else {
        fibo(2);
        cout << arr[N];
    }
}