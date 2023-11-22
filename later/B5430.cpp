// https://www.acmicpc.net/problem/5430
#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    while(T--){
        int flag = 0;
        deque<int> dq;
        string op, arr;
        cin >> op;
        cin >> arr;

        for (auto a: arr) {
            if (a != '[' and ']' and ',') dq.push_back(a);
            cout << a << "\n";
        }

        for (auto a: op){
            if (a == 'R'){
                for(auto i: dq) cout << i << " ";
                reverse(dq.rbegin(), dq.rend());
                for(auto i: dq) cout << i << " ";
            }
            else{
                if(dq.empty()){
                    flag = 1;
                    break;
                }
                else dq.pop_front();
            }
        }
        string ans;
        if (flag == 0) {
            ans += '[';
            for (int i = 0; i < dq.size() - 1; i++) ans += dq[i] + ',';
            ans += dq.back() + ']';
        } else ans = "error";
        cout << ans << "\n";
    }
    
}