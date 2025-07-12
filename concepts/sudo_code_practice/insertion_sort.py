from template import printf


def insertionSort(arr):
    n = len(arr)

    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key


def main():
    arr = [0, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    printf(arr)
    insertionSort(arr)
    printf(arr)


if __name__ == "__main__":
    main()
