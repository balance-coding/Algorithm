// https://www.acmicpc.net/problem/13549
// 시간초과 발생 원인: 0으로 시작했었는데, 시작 시간도 0이므로 중복 체크하는 경우가 많음
// 인덱스 에러 발생 원인: fill 사용할 때 배열 크기만큼 더해줘야된다!
// 틀린 이유: 우선순위를 고려해서 push_front, push_back 필요!
#include <bits/stdc++.h>
using namespace std;

int N, K;
int board[100001];

int bfs(){
    deque<int> Q;
    Q.push_back(N);
    board[N] = 0;

    while(!Q.empty()){
        int nloc = Q.front();
        Q.pop_front();

        if(nloc == K) return board[K];
        for(int n: {nloc-1, nloc+1, nloc*2}){
            if(0 <= n && n <= 100000 && board[n] == -1){
                if(n == nloc*2){
                    board[n] = board[nloc];
                    Q.push_front(n);
                } else {
                    board[n] = board[nloc]+1;
                    Q.push_back(n);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    fill(board, board+100001, -1);

    cout << bfs();
}