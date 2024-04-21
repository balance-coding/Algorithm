// https://www.acmicpc.net/problem/11286
#include <iostream>

using namespace std;

int N, x;

int heap[100005];
int size = 0;

int top() {
    if (size == 0) return 0;
    else return heap[1];
}

void push(int a) {
    heap[++size] = a;
    int index = size;
    while (index != 1) {
        int parent = index / 2;
        if (heap[parent] >= heap[index]) break;
        swap(heap[parent], heap[index]);
        index = parent;
    }
}

void pop() {
    heap[1] = heap[size--];
    int index = 1;
    while (2 * index <= size) {
        int left = 2 * index, right = 2 * index + 1;
        int max_child = left;
        if (right <= size && heap[right] > heap[left]) {
            max_child = right;
        }
        if (heap[index] >= heap[max_child]) break;
        swap(heap[index], heap[max_child]);
        index = max_child;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            cout << top() << "\n";
            if(size > 0) pop();
        } else {
            push(x);
        }
    }
}