#include <bits/stdc++.h>
using namespace std;

bool occur[2000001];
int n, x;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    cin >> x;

    int ans = 0;
    for(int i = 0; i<n; i++){
        if(x-arr[i] > 0 && occur[x-arr[i]]) ans++;
        occur[arr[i]] = true;
    }
    cout << ans;
}