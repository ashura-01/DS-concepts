from template import *


def partition(arr, low, high):
    pivot = arr[low]
    findBig = low
    findSmall = high

    while findBig < findSmall:
        while arr[findBig] <= pivot and findBig < high:
            findBig += 1

        while pivot < arr[findSmall]:
            findSmall -= 1

        if findBig <findSmall :
            swap(arr, findBig, findSmall)

    swap(arr, low, findSmall)


    return findSmall

def quickSort(arr, low, high):
    if(low<high):
        pivot = partition(arr, low, high)
        quickSort(arr, low, pivot-1)
        quickSort(arr, pivot+1, high)


def main():
    arr = [0, 39, 48, 87, 68, 5, 4, 3, 2, 1]
    printf(arr)
    quickSort(arr,0,len(arr)-1)
    printf(arr)

if __name__ == "__main__":
    main()
