// https://www.acmicpc.net/problem/11931
#include <bits/stdc++.h>
using namespace std;

int N, a;
bool arr[2000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a;
        arr[a+1000000] = true;
    }

    for(int i = 2000000; i >= 0; i--){
        if(arr[i]) cout << i-1000000 << '\n';
    }
}