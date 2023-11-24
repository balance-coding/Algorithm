// https://www.acmicpc.net/problem/2573
// 틀린 이유: line 19를 M이 아닌 N으로 했음... 이거는 진짜 실수하지 말자!
// 주의할 점: 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다 -> 탐색 필요 XX
#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[302][302];
int visit[302][302];
bool is_not_divided;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int findGroup(){
    for(int i = 0; i<N; i++){       // 0으로 빈칸 채우기
        fill(visit[i], visit[i]+M, 0);
    }
    int groupNum = 1;
    for(int i = 1; i<N-1; i++){
        for(int j = 1; j < M-1; j++){
            if(board[i][j] > 0 && visit[i][j] == 0){    // 빙산인 경우
                queue<pair<int, int>> Q;
                Q.push({i, j});
                visit[i][j] = groupNum;

                while(!Q.empty()){
                    auto cur = Q.front();
                    Q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];

                        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                        if(visit[ny][nx] != 0 || board[ny][nx] == 0) continue;
                        visit[ny][nx] = groupNum;
                        Q.push({ny, nx});
                    }
                }
                groupNum++;
            }
        }
    }

    if(groupNum == 1) is_not_divided = true;
    return groupNum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 1 입력받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int time = 0;

    // 2 모든 빙산이 0일 때까지 반복문
    while(findGroup()==2){
        int board_melting[N][M];
        for(int i = 0; i<N; i++) {       // 0으로 빈칸 채우기
            fill(board_melting[i], board_melting[i] + M, 0);
        }

        for(int i = 1; i < N-1; i++){     // 줄어들 크기 구하기
            for(int j = 1; j < M-1; j++){
                if(board[i][j] > 0){
                    for(int dir=0; dir<4; dir++){
                        int ny = i+dy[dir];
                        int nx = j+dx[dir];

                        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                        if(board[ny][nx] == 0) board_melting[i][j]++;
                    }
                }
            }
        }

        for(int i = 1; i < N-1; i++){     // 녹기
            for(int j = 1; j < M-1; j++){
                if(board_melting[i][j] > 0){
                    board[i][j] = max(0, board[i][j]-board_melting[i][j]);
                }
            }
        }
        // 잘 녹았는지 확인
//        cout << "after melt\n";
//        for(int i = 0; i < N; i++){
//            for(int j = 0; j < M; j++){
//                cout << board[i][j] << ' ';
//            }
//            cout << '\n';
//        }
        time++;
    }

    if(is_not_divided) cout << 0;
    else cout << time;

}