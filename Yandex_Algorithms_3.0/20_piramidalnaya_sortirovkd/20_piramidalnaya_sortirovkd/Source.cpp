#include<iostream>
#include<vector>
using namespace std;

void push_heap(vector<int>& heap, int x) {
    heap.push_back(x);
    long long pos = heap.size() - 1;
    while (pos > 0 && heap[pos] < heap[(pos - 1) / 2]) {
        swap(heap[pos], heap[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
    }
}

int pop_heap(vector<int>& heap) {
    int ans = heap[0];//это ответ тк наверху листа стоит макс число 
    heap[0] = heap[heap.size() - 1];//вставили в начало последний элеент
    long long pos = 0;//индекс в массиве который прсеиваем вниз
    while (pos * 2 + 2 < heap.size()) {
        int max_son_index = pos * 2 + 1;
        if (heap[pos * 2 + 2] < heap[max_son_index]) {
            max_son_index = pos * 2 + 2;
        }
        if (heap[pos] > heap[max_son_index]) {
            swap(heap[pos], heap[max_son_index]);
            pos = max_son_index;
        }
        else {
            break;
        }
    }
    heap.pop_back();
    return ans;
}

int main() {
    int k = 0;
    vector<int> heap;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int number;
        cin >> number;
        push_heap(heap, number);
    }

    while (heap.size() > 0) {
        cout<<pop_heap(heap);
        if (heap.size() != 0) {
            cout << " ";
        }
    }
    return 0;
}