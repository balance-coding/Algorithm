// https://www.acmicpc.net/problem/6593
#include <bits/stdc++.h>
using namespace std;

int L, R, C;
string board[32][32];
int dist[32][32][32];
int dy[6] = {1, 0, -1, 0, 0, 0};
int dx[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int y, x, z;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        cin >> L >> R >> C;

        if(L == 0 && R == 0 && C == 0) break;   // break 조건

        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                cin >> board[i][j];
            }
        }

        int sy, sx, sz, ey, ex, ez;
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                for(int k = 0; k < C; k++){
                    if(board[i][j][k] == 'S'){
                        sy = i;
                        sx = j;
                        sz = k;
                    }
                    else if(board[i][j][k] == 'E'){
                        ey = i;
                        ex = j;
                        ez = k;
                    }
                    dist[i][j][k] = -1;
                }
            }
        }

        queue<tuple<int, int, int>> Q;
        Q.push(make_tuple(sy, sx, sz));
        dist[sy][sx][sz] = 0;

        while(!Q.empty()){
            tuple<int, int, int> cur = Q.front();
            tie(y, x, z) = cur;
            Q.pop();

            for(int dir = 0; dir < 6; dir++){
                int ny = y+dy[dir];
                int nx = x+dx[dir];
                int nz = z+dz[dir];

                if(ny < 0 || ny >= L || nx < 0 || nx >= R || nz < 0 || nz >= C) continue;
                if(dist[ny][nx][nz] > -1 || board[ny][nx][nz] == '#') continue;
                dist[ny][nx][nz] = dist[y][x][z] + 1;
                Q.push(make_tuple(ny, nx, nz));
            }
        }

        if(dist[ey][ex][ez] == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << dist[ey][ex][ez] << " minute(s).\n";
    }
}