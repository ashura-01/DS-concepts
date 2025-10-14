#include <iostream>
#include <vector>
using namespace std;

vector<int> heap = {0}; // 1-indexed heap
int heapsize = 0;

void insertHeap(int value)
{
    heapsize++;
    if (heapsize < heap.size())
        heap[heapsize] = value;
    else
        heap.push_back(value);

    int i = heapsize;
    while (i > 1 && heap[i / 2] < heap[i])
    {
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}

void deleteHeap()
{
    if (heapsize < 1)
        return;

    swap(heap[1], heap[heapsize]);
    heapsize--;

    int i = 1;
    int j = 2 * i;
    while (j <= heapsize)
    {
        if (j + 1 <= heapsize && heap[j + 1] > heap[j])
            j++;
        if (heap[i] < heap[j])
        {
            swap(heap[i], heap[j]);
            i = j;
            j = 2 * i;
        }
        else
        {
            break;
        }
    }
}

void heapSort(int n)
{
    heapsize = 0;
    for (int i = 1; i <= n; i++)
        insertHeap(heap[i]);
    for (int i = n; i >= 2; i--)
        deleteHeap();
}

int main()
{
    vector<int> arr = {50, 30, 40, 10, 60};
    int n = arr.size();

    // Copy array into 1-indexed global heap
    heap = {0}; // reset heap
    for (int i = 0; i < n; i++)
        heap.push_back(arr[i]);

    heapSort(n);

    cout << "Sorted array: ";
    for (int i = 1; i <= n; i++)
        cout << heap[i] << " ";
    cout << endl;

    return 0;
}
