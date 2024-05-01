// https://www.acmicpc.net/problem/1929
#include <iostream>
#include <vector>

using namespace std;

int M, N;

vector<bool> number(1000001, true);

void solve(int n) {
    number[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!number[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            number[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    solve(N);
    for (int i = M; i <= N; i++) {
        if (number[i]) cout << i << "\n";
    }

}