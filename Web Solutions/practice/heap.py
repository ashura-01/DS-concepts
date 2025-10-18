from typing import List

# ------------------- Min Heap Functions -------------------
def heapify_min(heap: List, n: int, i: int):
    smallest = i
    left = 2 * i
    right = 2 * i + 1

    if left <= n and heap[left] < heap[smallest]:
        smallest = left
    if right <= n and heap[right] < heap[smallest]:
        smallest = right

    if smallest != i:
        heap[i], heap[smallest] = heap[smallest], heap[i]
        heapify_min(heap, n, smallest)


def buildHeap_min(arr: List):
    n = len(arr) - 1
    for i in range(n // 2, 0, -1):
        heapify_min(arr, n, i)


def insert_min(heap: List, value: int):
    heap.append(value)
    current = len(heap) - 1

    while current > 1:
        parent = current // 2
        if heap[current] < heap[parent]:
            heap[current], heap[parent] = heap[parent], heap[current]
            current = parent
        else:
            break


def delete_min(heap: List):
    size = len(heap) - 1
    if size < 1:
        return
    heap[1], heap[size] = heap[size], heap[1]
    heap.pop()
    size -= 1
    for i in range(size // 2, 0, -1):
        heapify_min(heap, size, i)


# ------------------- Max Heap Functions (existing) -------------------
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
    while current > 1:
        parent = current // 2
        if heap[current] > heap[parent]:
            heap[current], heap[parent] = heap[parent], heap[current]
            current = parent
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


# ------------------- Main Function -------------------
if __name__ == "__main__":
    # Max-heap
    max_heap = [None, 2, 3, 7, 5, 8, 9, 6, 0]
    buildHeap(max_heap)
    print("Max-Heap after building:", max_heap)
    insert(max_heap, 100)
    print("Max-Heap after inserting 100:", max_heap)
    delete(max_heap)
    print("Max-Heap after deleting root:", max_heap)

    print("\n---------------------------\n")

    # Min-heap
    min_heap = [None, 2, 3, 7, 5, 8, 9, 6, 0]
    buildHeap_min(min_heap)
    print("Min-Heap after building:", min_heap)
    insert_min(min_heap, 1)
    print("Min-Heap after inserting 1:", min_heap)
    delete_min(min_heap)
    print("Min-Heap after deleting root:", min_heap)
