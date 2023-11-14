#include <bits/stdc++.h>
using namespace std;

int main(void) {
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.size() << "\n";

    if(s.empty()) cout << "s is empty\n";
    else cout << "s is not empty\n";

    s.pop();
    cout << s.top() << "\n";

    s.pop();
    cout << s.top() << "\n";

    s.pop();
    if(s.empty()) cout << "s is empty\n";
    cout << s.top() << "\n";
}