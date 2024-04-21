// https://www.acmicpc.net/problem/1927
#include <iostream>

using namespace std;

int heap[100005];
int size = 0;

int N, num;

void push(int x) {
    heap[++size] = x;
    int index = size;
    while (index != 1) {
        int parent = index / 2;
        if (heap[parent] <= heap[index]) break;
        swap(heap[parent], heap[index]);
        index = parent;
    }
}

int top() {
    return heap[1];
}

void pop() {
    heap[1] = heap[size--];
    int index = 1;
    while (2 * index <= size) {
        int left = 2 * index, right = 2 * index + 1;
        int min_child = left;
        if (right <= size && heap[right] < heap[left]) {
            min_child = right;
        }
        if (heap[index] <= heap[min_child]) break;
        swap(heap[index], heap[min_child]);
        index = min_child;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num == 0) {
            if (size == 0) {
                cout << 0 << '\n';
            } else {
                cout << top() << '\n';
                pop();
            }
        } else {
            push(num);
        }
    }
}