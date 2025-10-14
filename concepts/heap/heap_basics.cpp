#include <bits/stdc++.h>
using namespace std;

void insertHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    int i = heap.size() - 1;
    while (i > 1 && heap[i / 2] < heap[i]) {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}

void heapify1(vector<int>& heap, int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && heap[left] > heap[largest])
        largest = left;
    if (right <= n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify1(heap, n, largest);
    }
}

void deleteHeap(vector<int>& heap) {
    int n = heap.size() - 1;
    if (n < 1) return;

    heap[1] = heap[n];
    heap.pop_back();

    heapify1(heap, heap.size() - 1, 1);
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    cout << "=== INSERTION & DELETION IN 1-BASED HEAP ===" << endl;
    vector<int> heap(1);

    insertHeap(heap, 50);
    insertHeap(heap, 30);
    insertHeap(heap, 40);
    insertHeap(heap, 10);
    insertHeap(heap, 20);
    insertHeap(heap, 35);

    cout << "Heap after insertions: ";
    for (int i = 1; i < heap.size(); i++) cout << heap[i] << " ";
    cout << endl;

    deleteHeap(heap);
    cout << "Heap after deleting root: ";
    for (int i = 1; i < heap.size(); i++) cout << heap[i] << " ";
    cout << endl;

    cout << "\n=== HEAP SORT ===" << endl;
    vector<int> arr = {50, 30, 40, 10, 20, 35};
    heapSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
