// https://www.acmicpc.net/problem/15649
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool used[10];

void func(int k){   // 현재 택한 수
    if(k==M){   // M개를 선택했으면
        for(int i = 0; i<M; i++){
            cout << arr[i] << ' ';  // arr에 기록해둔 수를 기록
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++){    // 1~N 까지의 수에 대해
        if(!used[i]){           // 아직 사용되지 않았으면
            arr[k] = i;         // k번째 수를 i로 정함
            used[i] = true;     // i를 사용되었다고 표시
            func(k+1);      // 다음 수를 정하려 한 단계 더 들어감!
            used[i] = false;    // k번째 수를 1로 정한 모든 경우에 대해 확인했으니 사용하지 않은 상태로 되돌리기!
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    func(0);
}