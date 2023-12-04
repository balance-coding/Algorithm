// https://www.acmicpc.net/problem/11931
#include <bits/stdc++.h>
using namespace std;

int N, a;
int arr[2000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a;
        arr[a+1000000]++;
    }

    for(int i = 0; i < 2000001; i++){
        if(arr[i] > 0){
            for(int j = 0; j < arr[i]; j++) cout << i-1000000 << '\n';
        }
    }
}