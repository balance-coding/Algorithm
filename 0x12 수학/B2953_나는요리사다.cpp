// https://www.acmicpc.net/problem/2953
#include <bits/stdc++.h>
using namespace std;

int score, winner = 0;
int a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < 6; i++){
        int temp = 0;
        for(int j = 0; j < 4; j++){
            cin >> a;
            temp += a;
        }
        if(score < temp){
            winner = i;
            score = temp;
        }
    }
    cout << winner << ' ' << score;
}