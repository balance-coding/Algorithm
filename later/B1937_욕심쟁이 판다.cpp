// https://www.acmicpc.net/problem/1937
#include <bits/stdc++.h>
using namespace std;

int n;
int board[502][502];
bool visit[502][502];
int dp[502][502];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void recur(int y, int x, int cnt);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    } // for

    stack<pair<int, int>> s;

    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            visit[i][j] = true;
            s.push({i, j});
            while(!s.empty()){
                pair<int, int> cur = s.top();
                s.pop();

                for(int dir=0; dir<4; dir++){
                    int ny = cur.first + dy[dir];
                    int nx = cur.second + dx[dir];

                    if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                    if(visit[ny][nx] || board[ny][nx] != 1)
                }
            }
        }
    }


}