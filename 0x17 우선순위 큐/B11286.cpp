// https://www.acmicpc.net/problem/11286
#include <iostream>
#include <queue>

using namespace std;

int N, x;

class cmp {
public:
    bool operator()(int a, int b) {
        if (abs(a) != abs(b)) return abs(a) > abs(b);
        else return (a > 0 && b < 0);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    priority_queue<int, vector<int>, cmp> pq;
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