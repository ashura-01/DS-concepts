#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int lowerBound(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size();

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int binarySearch(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int32_t main()
{
    int n; 
    cout<<"Enter the size of the vector: ";cin>>n;

    vector<int> arr(n);
    int target;

    cout<<"Enter the vector: ";
    for(auto &elem : arr) cin>>elem;

    cout<<"Enter a value to search: "; cin>>target;


    insertionSort(arr);

    cout << "Sorted vector: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << endl;

    int index = binarySearch(arr, target);
    if (index != -1)
    {
        cout << "Value " << target << " found at index: " << index << endl;
    }
    else
    {
        int pos = lowerBound(arr, target);
        cout << "Value " << target << " can be inserted at index: " << pos << " to maintain sorted order." << endl;
    }

    return 0;
}