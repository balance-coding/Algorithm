#include <bits/stdc++.h>
using namespace std;

int arr[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 1;
    int n;

    for(int i = 0; i < 3; i++){
        cin >> n;
        ans *= n;
    }

    for(auto e: to_string(ans)){
        arr[e-'0']++;
    }

    for(auto e: arr){
        cout << e << "\n";
    }
}