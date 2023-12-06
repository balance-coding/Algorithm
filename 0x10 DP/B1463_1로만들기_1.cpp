// https://www.acmicpc.net/problem/1463
#include <bits/stdc++.h>
using namespace std;

int N, cur;
int arr[1000001];
queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    q.push(N);

    while(!q.empty()){
        cur = q.front();
        q.pop();

        if(cur == 1) break;

        if(cur % 3 == 0 && cur / 3 > 0 && arr[cur / 3] == 0){
            arr[cur / 3] = arr[cur]+1;
            q.push(cur/3);
        }
        if(cur % 2 == 0 && cur / 2 > 0 && arr[cur / 2] == 0){
            arr[cur / 2] = arr[cur]+1;
            q.push(cur/2);
        }
        if(cur - 1 > 0 && arr[cur - 1] == 0){
            arr[cur-1] = arr[cur]+1;
            q.push(cur-1);
        }
    }
    cout << arr[1];
}