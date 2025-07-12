def printf(arr):
    n = len(arr)
    print("-----" * n + "-")
    for i in range(n):
        print(f"| {i:2d} ", end="")
    print("|")
    for _ in range(n):
        print("     ", end="")
    print()
    for val in arr:
        print(f"| {val:2d} ", end="")
    print("|")
    print("-----" * n + "-")
    
def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]
