// https://www.acmicpc.net/problem/1926
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool visit[502][502];     // 해당 칸을 방문했는지 여부 저장
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int arr[N+1][M+1];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    int ans1 = 0;
    int ans2 = 0;
    // 탐색
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M ; j++){
            int cnt = 0;
            if((arr[i][j] == 1) && !visit[i][j]){
                ans1++;
                queue<pair<int, int>> Q;
                Q.push({i, j});
                visit[i][j] = true;

                while (!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    cnt++;
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(visit[nx][ny] || arr[nx][ny] != 1) continue;
                        visit[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
                ans2 = max(ans2, cnt);
            }
        }
    }
    cout << ans1 << '\n' << ans2;
}