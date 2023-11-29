// https://www.acmicpc.net/problem/6603
#include <bits/stdc++.h>
using namespace std;

int K;
int arr[49];
int input[49];
bool isUsed[49];

void func(int num){
    if(num == 6){
        for(int i = 0; i<6; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < K; i++){
        if(!isUsed[i]){
            cout << "num: " << num << "i: " << i << '\n';
            isUsed[i] = true;
            arr[num] = input[i];
            func(num+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        cin >> K;
        if(K == 0) break;
        for(int i = 0; i < K; i++) cin >> input[i];
        func(0);
        cout << '\n';
    }

}