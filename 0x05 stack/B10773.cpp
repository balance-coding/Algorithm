#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    cin >> n;

    while(n--){
        int a;
        cin >> a;

        if (a == 0) s.pop();
        else s.push(a);
    }

    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    cout << ans;
}