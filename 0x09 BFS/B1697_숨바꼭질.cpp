// https://www.acmicpc.net/problem/1697
#include <bits/stdc++.h>
using namespace std;

int N, K;
int board[100001];

int bfs(){
    queue<int> Q;
    Q.push(N);

    while(!Q.empty()){
        int num = Q.front();
        Q.pop();

        if(num == K)
            return board[num];
        for(int nx: {num-1, num+1, num*2}){
            if(0<=nx && nx <= 100000 && board[nx] == 0){
                board[nx] = board[num]+1;
                Q.push(nx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(board, board+100001, 0);

    cin >> N >> K;

    cout << bfs();
}