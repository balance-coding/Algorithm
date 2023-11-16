#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
int N, M, a, idx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        dq.push_back(i);
    }

    int ans = 0;
    while(M--){
        cin >> a;

        for(int i = 0; i<dq.size(); i++){
            if(dq[i] == a){
                idx = i;
                break;
            }
        }

        if(idx < dq.size()-idx){
            ans += idx;

            while(idx--){
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
            }
        }
        else{
            idx = dq.size()-idx;
            ans += idx;

            while(idx--){
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
            }
        }
        dq.pop_front();
    }
    cout << ans;
}