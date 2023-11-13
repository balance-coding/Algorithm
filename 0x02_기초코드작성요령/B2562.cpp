#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int line = 0;
    int N;

    for(int i=0; i<9; i++){
        cin >> N;
        if(ans < N){
            ans = N;
            line = i+1;
        }
    }
    cout << ans << "\n" << line;
}