// https://www.acmicpc.net/problem/2178
#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[102];
int dist[102][102];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> board[i];
        fill(dist[i], dist[i]+m, -1);
    }

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 0;

    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(dist[ny][nx] >= 0 || board[ny][nx] == '0') continue;
            dist[ny][nx] = dist[cur.first][cur.second]+1;
            Q.push({ny, nx});
        }
    }
    cout << dist[n-1][m-1]+1;
}