from template import *

def ternarySearch(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:

        mid1 = low + (high - low) // 3
        mid2 = high - (high - low) // 3

        if arr[mid1] == target:
            return mid1
        if arr[mid2] == target:
            return mid2

        if target < arr[mid1]:
            high = mid1 - 1
        elif target > arr[mid2]:
            low = mid2 + 1
        else:
            low = mid1 + 1
            high = mid2 - 1

    return -1

def main():
    size = int(input("input the size: "))
    arr = []

    for i in range(0,size):
        elem = int(input(f"enter the {i}th element: "))
        arr.append(elem)

    printf(arr)

    target = int(input(f"enter the target: "))

    index = ternarySearch(arr,target)

    print(f"the elemenet {arr[index]} found at ---->{index}")




if __name__ == "__main__":
    main()