#include <bits/stdc++.h>
using namespace std;

int func2_my(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i]+arr[j] == 100) return 1;
        }
    }
    return 0;
}

int func2_new(int arr[], int n){
    int occur[101] = {};

    for(int i = 0; i < n; i++){
        if(occur[100-arr[i]]) return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[4] = {4, 13, 63, 87};

    int res = func2_new(arr, 4);

    cout << res;
}
