from template import *  

def selectionSort(arr):
    n = len(arr)

    for i in range(0,n - 1):
        mindex = i

        for j in range(i + 1, n):

            if arr[j] < arr[mindex]:
                mindex = j
                
        swap(arr, i, mindex)

def main():
    arr = [0, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    printf(arr)
    selectionSort(arr)
    printf(arr)

if __name__ == "__main__":
    main()
