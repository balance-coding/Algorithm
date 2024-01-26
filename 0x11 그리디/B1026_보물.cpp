// https://www.acmicpc.net/problem/1026
#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;
int arrA[50], arrB[50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> arrA[i];
    for (int i = 0; i < N; i++) cin >> arrB[i];

    sort(arrA, arrA + N);
    sort(arrB, arrB + N);

    for (int i = 0; i < N; i++) {
        ans += arrA[i] * arrB[N - i - 1];
    }
    cout << ans;
}