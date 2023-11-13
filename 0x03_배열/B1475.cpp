#include <bits/stdc++.h>
using namespace std;

int arr[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for(auto c:s){
        if(c=='6' || c=='9'){
            if(arr[6] > arr[9]) arr[9]++;
            else arr[6]++;
        }
        else{
            arr[c-'0']++;
        }
    }
    int ans = 0;
    for(auto i: arr){
        ans = max(ans, i);
    }
    cout << ans;
}