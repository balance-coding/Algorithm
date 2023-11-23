// https://www.acmicpc.net/problem/9466
#include <bits/stdc++.h>
using namespace std;

int N;
int board[102][102];
bool visit[102][102];
queue<pair<int, int>> loc;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // 1 입력받기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    // 2 빈칸인지 확인하기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 1){
                for(int dir = 0; dir < 4; dir++){
                    int ni = i + dy[dir];
                    int nj = j + dx[dir];

                    if(ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
                    if(board[ni][nj] == 0) {
                        loc.push({i, j});
                        break;
                    }
                }
            }
        }
    }
    // 3 같은 그룹인지 확인하기
    int group = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit[i][j] and board[i][j] == 1){
                queue<pair<int, int>> Q;
                Q.push({i, j});
                visit[i][j] = true;
                board[i][j] = group;

                while(!Q.empty()){
                    auto curboard = Q.front();
                    Q.pop();
                    for(int dir = 0; dir<4; dir++){
                        int ni = curboard.first + dy[dir];
                        int nj = curboard.second + dx[dir];

                        if(ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
                        if(visit[ni][nj] || board[ni][nj] == 0) continue;

                        Q.push({ni, nj});
                        board[ni][nj] = group;
                        visit[ni][nj] = true;
                    }
                }
                group++;
            }
        }
    }

    int ans = numeric_limits<int>::max();

    while(!loc.empty()){
        pair<int, int> nloc = loc.front();
        loc.pop();

        queue<pair<int, int>> S;
        int dist[N][N];
        memset(dist, -1, sizeof(dist));
        bool isEscape = false;
        S.push(nloc);
        dist[nloc.first][nloc.second] = 0;

        while(!S.empty()){
            if(isEscape) break;
            auto cur = S.front();
            S.pop();

            for(int dir = 0; dir < 4; dir++){
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];

                if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if(dist[ny][nx] != -1 || board[ny][nx] == board[nloc.first][nloc.second]) continue;

                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                if(board[ny][nx] > 0 and board[ny][nx] != board[nloc.first][nloc.second]){
                    isEscape = true;
                    ans = min(ans, dist[ny][nx]-1);
                    break;
                }
                S.push({ny, nx});
            }
        }
    }
    cout << ans;
}