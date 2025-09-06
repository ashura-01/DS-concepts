#include <bits/stdc++.h>
using namespace std;

void print(const vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; ++i)
        cout << "-----";
    cout << "-\n";

    for (int i = 0; i < n; ++i)
        cout << "| " << setw(2) << i << " ";
    cout << "|\n";

    for (int i = 0; i < n; ++i)
        cout << "     ";
    cout << "\n";

    for (int i = 0; i < n; ++i)
        cout << "| " << setw(2) << arr[i] << " ";
    cout << "|\n";

    for (int i = 0; i < n; ++i)
        cout << "-----";
    cout << "-\n";
}

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

void revarr(vector<int> &arr, int k)
{
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr = {1,2,3,4,5,6};

    print(arr);
    insertionSort(arr);
    print(arr);

    int target = 4;

    cout<<"binary search: "<<binarySearch(arr, target)<<endl;
    cout<<"binary search lower: "<<lowerBound(arr, target)<<endl;

    return 0;
}
