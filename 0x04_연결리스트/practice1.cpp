#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
    dat[unused] = num;          // 1. 새로운 원소 생성
    pre[unused] = addr;         // 2. 새 원소 pre 값에 삽입할 위치의 주소 대입
    nxt[unused] = nxt[addr];    // 3. 새 원소 nxt 값에 삽입할 위치의 nxt 값 대입

    if(nxt[addr] != -1) pre[nxt[addr]] = unused;    // 4. 삽입할 위치의 다음 원소의 pre값을 새 원소로 변경
    nxt[addr] = unused;         // 5. 삽입할 위치의 nxt 값을 새 원소로 변경
    unused++;                   // 6. unused 1 증가
}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];     // 1. 이전 위치의 nxt를 삭제할 위치의 nxt로 변경
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];     // 2. 다음 위치의 pre를 삭제할 위치의 pre로 변경
}

void traverse(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test(){
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test(){
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    insert_test();
    erase_test();
}