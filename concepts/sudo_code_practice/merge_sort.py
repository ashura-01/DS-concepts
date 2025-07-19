from template import *

infinity = 10**18 

def mergeSort(arr, low, high):
    if low < high :
        mid = (low+high)//2

        mergeSort(arr,low, mid)
        mergeSort(arr,mid+1,high)
        merge(arr, low, mid, high)

def merge(arr, low, mid,high):
    sizeLeft = mid-low+1
    sizeRight = high-mid

    arrLeft = []
    arrRight = []

    for i in range(0,sizeLeft):
        arrLeft.append(arr[low+i])

    for i in range(0,sizeRight):
        arrRight.append(arr[mid+1+i])

    arrLeft.append(infinity)
    arrRight.append(infinity)

    i = 0 
    j =0

    for k in range(low, high+1):
        if arrLeft[i] < arrRight[j]:
            arr[k] = arrLeft[i]
            i+=1
        else :
            arr[k]=arrRight[j]
            j+=1



def main():
    arr = [0, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    printf(arr)
    low = 0
    high = len(arr)-1
    mergeSort(arr,low,high)
    printf(arr)

if __name__ == "__main__":
    main()