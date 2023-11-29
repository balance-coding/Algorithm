// https://www.acmicpc.net/problem/9663
#include <bits/stdc++.h>
using namespace std;

int N;
bool isUsed1[40];   // - 방향(column)을 차지하고 있는지
bool isUsed2[40];   // / 방향 대각선을 차지하고 있는지
bool isUsed3[40];   // \ 방향 대각선을 차지하고 있는지
int cnt = 0;

void func(int cur){ // cur번째 row에 말을 배치할 예정
    if(cur == N){   // N개를 놓는데 성공했다면
        cnt++;
        return;
    }

    for(int i = 0; i<N; i++){   // (cur, i)에 퀸을 놓을 예정
        if(isUsed1[i] || isUsed2[i+cur] || isUsed3[cur-i+N-1]) continue;    // column이나 대각선 중에 문제가 있는 경우
        isUsed1[i] = true;
        isUsed2[i+cur] = true;
        isUsed3[cur-i+N-1] = true;
        func(cur+1);
        isUsed1[i] = false;
        isUsed2[i+cur] = false;
        isUsed3[cur-i+N-1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    func(0);
    cout << cnt;
}