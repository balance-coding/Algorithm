// https://www.acmicpc.net/problem/10989
#include <bits/stdc++.h>
using namespace std;

int N, a;
int arr[10001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a;
        arr[a]++;
    }

    for(int i = 0; i < 10001; i++){
        for(int j = 0; j < arr[i]; j++) cout << i << '\n';
    }
}