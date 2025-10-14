from typing import List

heap = [0]
heapsize = 0


def insertHeap(value: int):
    global heap, heapsize
    heapsize += 1
    if heapsize >= len(heap):
        heap.append(value)
    else:
        heap[heapsize] = value
    i = heapsize
    while i > 1 and heap[i // 2] < heap[i]:
        heap[i], heap[i // 2] = heap[i // 2], heap[i]
        i //= 2


def deleteHeap():
    global heap, heapsize
    if heapsize < 1:
        return
    heap[1], heap[heapsize] = heap[heapsize], heap[1]
    heapsize -= 1
    i = 1
    j = 2 * i
    while j <= heapsize:
        if j + 1 <= heapsize and heap[j + 1] > heap[j]:
            j += 1
        if heap[i] < heap[j]:
            heap[i], heap[j] = heap[j], heap[i]
            i = j
            j = 2 * i
        else:
            break


def heapSort():
    global heap, heapsize
    n = len(heap) - 1
    heapsize = 0
    for i in range(1, n + 1):
        insertHeap(heap[i])
    for i in range(n, 1, -1):
        deleteHeap()


if __name__ == "__main__":
    heap = [0, 50, 30, 40, 10, 60]
    heapSort()
    print("Sorted array:", heap[1:])
