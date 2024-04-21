#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int N, x;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    priority_queue<unsigned int, vector<unsigned int>, greater<>> pq;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
}