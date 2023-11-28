// https://www.acmicpc.net/problem/11729
#include <bits/stdc++.h>
using namespace std;

int N;

void func(int a, int b, int n){
    if(n==1){
        cout << a << ' ' << b << '\n';  // 원판 1개를 옮김
        return;
    }

    func(a, 6-a-b, n-1);        // n-1개의 원판을 경유지에서 a로 옮김
    cout << a << ' ' << b << '\n';      // 원판 n을 a에서 b로 옮김
    func(6-a-b, b, n-1);        // n-1개의 원판을 경유지에서 b로 옮김
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    cout << (1<<N)-1 << '\n';       // 1<<K -> 2^K임..!
    func(1, 3, N);              // k개의 원판을 1 -> 3 옮김
}