from template import *

infinity = 10**18


def evenOddMergeSort(arr, low, high):
    if low < high:
        mid = (low + high) // 2
        evenOddMergeSort(arr, low, mid)
        evenOddMergeSort(arr, mid + 1, high)
        merge(arr, low, mid, high)


def merge(arr, low, mid, high):
    lefthalf = mid - low + 1
    righthalf = high - mid

    arrleft = []
    arrright = []

    # copying data to halves
    for i in range(lefthalf):
        arrleft.append(arr[low + i])
    for i in range(righthalf):
        arrright.append(mid + 1 + i)

    arrleft.append(infinity)
    arrright.append(infinity)

    # arranging those in arr
    i = 0
    j = 0

    for k in range(low, high + 1):
        if arrleft[i] < arrright[j] and arrleft[i] % 2 == 0:
            arr[k] = arrleft[i]
            i += 1
        else:
            arr[k] = arrright[j]
            j += 1

def main():
    arr = [0, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    printf(arr)
    low = 0
    high = len(arr) - 1
    evenOddMergeSort(arr, low, high)
    printf(arr)


if __name__ == "__main__":
    main()
