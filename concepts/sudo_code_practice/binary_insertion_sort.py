from template import printf  

def binarySearch(arr, target, high):
    low = 0
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return low  

def binaryInsertionSort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        index = binarySearch(arr, key, j)
        while j >= index:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def main():
    arr = [0, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    printf(arr)
    binaryInsertionSort(arr)
    printf(arr)

if __name__ == "__main__":
    main()
