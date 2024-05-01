// https://www.acmicpc.net/problem/11653
#include <iostream>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            cout << i << '\n';
            N /= i;
        }
    }
    if (N != 1) cout << N;
}