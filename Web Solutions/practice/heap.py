from typing import List


def heapify(heap: List, n: int, i: int):
    largest = i
    left = 2 * i
    right = 2 * i + 1

    if left <= n and heap[left] > heap[largest]:
        largest = left
    if right <= n and heap[right] > heap[largest]:
        largest = right

    if largest != i:
        heap[i], heap[largest] = heap[largest], heap[i]
        heapify(heap, n, largest)


def buildHeap(arr: List):
    n = len(arr) - 1
    for i in range(n // 2, 0, -1):
        heapify(arr, n, i)


def insert(heap, value):
    heap.append(value)
    current = len(heap)-1

    while current >1:
        parent = current//2

        if heap[current]>heap[parent]:
            heap[current],heap[parent] = heap[parent],heap[current]
            current=parent
        else:
            break

def delete(heap):
    size = len(heap) - 1
    if size < 1:
        return
    heap[1], heap[size] = heap[size], heap[1]
    heap.pop()
    size -= 1
    for i in range(size // 2, 0, -1):
        heapify(heap, size, i)
    

if __name__ == "__main__":
    arr = [None, 2, 3, 7, 5, 8, 9, 6, 0]
    buildHeap(arr)
    insert(arr,100)
    print(arr)
    delete(heap=arr)
    print(arr)
