#include <bits/stdc++.h>
using namespace std;

int n, flag = 0;
int start = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    string ans;
    cin >> n;

    while(n--){
        int a;
        cin >> a;

        while(start<=a){
            s.push(start);
            ans += '+';
            start++;
        }

        if(s.top()==a){
            s.pop();
            ans += '-';
        }
        else{
            flag = 1;
            break;
        }
    }

    if(flag) cout << "NO";
    else
        for(auto w: ans) cout << w << "\n";
}