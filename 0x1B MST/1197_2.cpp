// https://www.acmicpc.net/problem/1197
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int V, E, a, b, c;
vector<pair<int, int>> adj[10005];
bool check[10005];  // 1번 정저미 MST 속한 여부

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int cnt = 0, ans = 0;

    priority_queue<tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>> pq;

    check[1] = 1;
    for(auto nxt:adj[1]) pq.push({nxt.first, 1, nxt.second});

    while(cnt < V-1){
        int cost, s, e;
        tie(cost, s, e) = pq.top();
        pq.pop();
        if(check[e]) continue;
        ans += cost;
        check[e] = 1;
        cnt++;
        for(auto nxt: adj[e]){
            if(!check[nxt.second]) pq.push({nxt.first, e, nxt.second});
        }
    }

    cout << ans;
}