from template import *

def binarySearch(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1

def main():
    arr = []
    size = int(input("Enter size of array: "))

    print(f"Enter {size} elements:")
    
    for _ in range(size):
        elem = int(input())
        arr.append(elem)

    printf(arr)

    target = int(input("Enter target to search: "))
    result = binarySearch(arr, target)

    if result != -1:
        print(f"Element found at index {result}")
    else:
        print("Element not found")

if __name__ == "__main__":
    main()
