// https://www.acmicpc.net/problem/1197
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int V, E, a, b, c;
tuple<int, int, int> edges[100005];
vector<int> p;

// find 함수: 경로 압축을 사용한 루트 찾기
int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool union_sets(int u, int v) {
    int root_u = find(u), root_v = find(v);

    if(root_u != root_v){
        p[root_v] = root_u;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    p.resize(V+1);

    // 간선 정보 입력 받기
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }

    // 모든 정점을 자신을 루트로 초기화
    for(int i = 1; i <= V; i++){
        p[i] = i;
    }

    // 간선을 가중치 기준으로 정렬
    sort(edges, edges + E);

    int cnt = 0, ans = 0;

    // 간선을 하나씩 확인하며 MST를 구성
    for (int i = 0; i < E; i++) {
        int s, e, cost;
        tie(cost, s, e) = edges[i];
        if(!union_sets(s, e)) continue;
        ans += cost;
        cnt++;
        if(cnt == V-1) break;
    }
    cout << ans;
}