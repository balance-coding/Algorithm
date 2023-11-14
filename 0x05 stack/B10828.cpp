#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> st;

    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;

        if(s == "push"){
            int op;
            cin >> op;
            st.push(op);
        }
        else if(s == "top"){
            if(!st.empty()){
                cout << st.top() << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(s == "size"){
            cout << st.size() << "\n";
        }
        else if(s == "empty"){
            if(!st.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << 1 << "\n";
            }
        }
        else{
            if(!st.empty()){
                cout << st.top() << "\n";
                st.pop();
            }
            else{
                cout << "-1" << "\n";
            }
        }
    }
}