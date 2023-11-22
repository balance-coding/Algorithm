// https://www.acmicpc.net/problem/4949
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        string sentence;
        getline(cin, sentence);
        if(sentence == ".") break;         // .이면 종료
        stack<char> s;
        bool isValid = true;
        for(auto c:sentence){
            if(c == '(' || c == '[') s.push(c);     // 시작 괄호 stack에 넣기
            else if(c==')'){
                if(s.empty() || s.top() != '('){        // stack이 비어있거나 괄호가 없으면..
                    isValid = false;
                    break;
                }
                s.pop();
            }
            else if(c == ']'){
                if(s.empty() || s.top() != '['){
                    isValid = false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()) isValid = false;
        if(isValid) cout << "yes\n";
        else cout << "no\n";
    }
}