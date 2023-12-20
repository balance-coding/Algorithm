// https://www.acmicpc.net/problem/1931
// task scheduling problem
#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[100000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i].second >> arr[i].first;
    }

    sort(arr, arr+N);
    int now = 0, ans = 0;
    for(int i = 0; i < N; i++){
        if(now > arr[i].second) continue;
        ans++;
        now = arr[i].first;
    }

    cout << ans;
}