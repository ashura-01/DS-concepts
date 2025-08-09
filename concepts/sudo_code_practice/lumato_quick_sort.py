from template import *


def partition(arr, low, high):
    pivot = arr[high]

    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            swap(arr, i, j)

    swap(arr, i + 1, high)

    return i + 1


def quickSort(arr, low, high):
    if low < high:
        pivot = partition(arr, low, high)
        quickSort(arr, low, pivot - 1)
        quickSort(arr, pivot + 1, high)


def main():
    arr = [0, 39, 48, 87, 68, 5, 4, 3, 2, 1]
    printf(arr)
    quickSort(arr, 0, len(arr) - 1)
    printf(arr)


if __name__ == "__main__":
    main()
