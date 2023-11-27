// https://www.acmicpc.net/problem/12851
// 틀린 이유: num == K 조건문을 for문 안에서 처리헀었음...
#include <bits/stdc++.h>
using namespace std;

int N, K;
int board[100001];
int cnt = 0;

void bfs(){
    queue<int> Q;
    Q.push(N);

    while(!Q.empty()){
        int num = Q.front();
        Q.pop();

        if(num == K){
            cnt++;
        } else{
            for(int nx: {num-1, num+1, num*2}){
                if(0<=nx && nx <= 100000 && (board[nx] == 0 || board[nx] == board[num]+1)){
                    board[nx] = board[num]+1;
                    Q.push(nx);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    fill(board, board+100001, 0);

    bfs();

    cout << board[K] << '\n' << cnt;
}