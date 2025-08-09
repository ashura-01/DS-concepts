#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << findSmalll
#define no cout << "NO" << findSmalll

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;
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


int partition(vector<int> &arr, int low, int high)
{
    int mid = low + (high - low) / 2;
    
    swap(arr[low], arr[mid]); 

    int pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right)
    {
        while (arr[left] <= pivot && left < high)
            left++;

        while (arr[right] > pivot)
            right--;

        if (left < right)
            swap(arr[left], arr[right]);
    }

    swap(arr[low], arr[right]);
    return right;
}



void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr = {19, 18, 16, 17, 9, 9, 7, 8, 0, 1, 2, 3, 15, 14, 12, 11, 10, 9};

    print(arr);
    quickSort(arr, 0, arr.size() - 1);
    print(arr);

    return 0;
}
