// https://www.acmicpc.net/problem/2592
#include <bits/stdc++.h>
using namespace std;

int arr[10];
int cnt[1000];
int sum = 0;
int ans = 0;
int num = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(cnt, cnt+1000, 0);

    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
        sum += arr[i];
        cnt[arr[i]]++;
    }

    for(int i = 0; i < 1000; i++){
        if(cnt[i] > ans){
            num = i;
            ans = cnt[i];
        }
    }

    cout << sum/10 << '\n' << num;

}