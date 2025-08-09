from template import *


def median(arr, low, high):
    mid = low + (high - low) // 2

    if arr[low] > arr[mid]:
        swap(arr, low, mid)

    if arr[low] > arr[high]:
        swap(arr, low, high)
        
    if arr[mid] > arr[high]:
        swap(arr, mid, high)

    swap(arr, mid, high)

    return arr[high]


def partition(arr, low, high):

    pivot = median(arr, low, high)

    i = low - 1

    for j in range(low, high):

        if arr[j] < pivot:
            i += 1
            swap(arr, i, j)

    swap(arr, i + 1, high)

    return i + 1


def quickSort(arr, low, high):

    if low < high:
        p = partition(arr, low, high)
        quickSort(arr, low, p - 1)
        quickSort(arr, p + 1, high)


def main():
    arr = [0, 39, 48, 87, 68, 5, 4, 3, 2, 1]
    printf(arr)
    quickSort(arr, 0, len(arr) - 1)
    printf(arr)


if __name__ == "__main__":
    main()
