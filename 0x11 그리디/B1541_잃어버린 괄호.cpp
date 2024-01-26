// https://www.acmicpc.net/problem/1541
#include <bits/stdc++.h>
using namespace std;

string input;
int tmp = 0, ans = 0, sign = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;
    for (char c: input) {
        if (c == '+' || c == '-') {
            ans += sign * tmp;
            if (c == '-') sign = -1;
            tmp = 0;
        } else {
            tmp *= 10;
            tmp += c - '0';
        }
    }
    ans += tmp * sign;
    cout << ans;
}