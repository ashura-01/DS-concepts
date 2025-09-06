
def medianSearch(arr):
    n = len(arr)
    low = min(arr)
    high= max(arr)

    while low<high:
        mid = low + (high-low)//2
        count = 0

        for i in arr:
            if i<=mid:
                count+=1
        if count >n//2:
            high=mid
        else:
            low=mid+1
    return low

if __name__ == "__main__":
    arr =[1,2,3,4,5,6,7,8]
    print(medianSearch(arr))