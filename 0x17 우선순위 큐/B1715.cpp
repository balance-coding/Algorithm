// https://www.acmicpc.net/problem/1715
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int N, x, n1, n2;
priority_queue<unsigned int, vector<unsigned int>, greater<>> pq;

int solve() {
    int sum = 0;
    while (pq.size() > 1) {
        n1 = pq.top();
        pq.pop();
        n2 = pq.top();
        pq.pop();
        sum += (n1 + n2);
        pq.push(n1 + n2);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        pq.push(x);
    }
    cout << solve();
}