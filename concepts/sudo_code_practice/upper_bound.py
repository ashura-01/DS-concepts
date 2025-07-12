from template import *

def upperBoundBinarySearch(arr, target):
    low = 0
    high = len(arr)

    while low < high :
        mid = (low+high)//2
        
        if arr[mid] <= target:
            low = mid+1
        else:
            high = mid
    return low



def main():
    arr =[0,1,2,3,4,4,4,4,4,5,6,7,8,9]
    printf(arr)
    target = 4

    index = upperBoundBinarySearch(arr, target)

    print(f"the target {arr[index]} loc ----> {index}")

if __name__ == "__main__":
    main()
