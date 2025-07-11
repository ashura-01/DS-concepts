#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int solveProblem(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size();

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int lastOccBinarySearch(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int indx= -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            low = mid + 1;
            indx= mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return indx;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4, 5, 5, 5, 5, 6, 7, 8, 9};
    int target = 5;

    int index = lastOccBinarySearch(arr, target);
    cout << index << " value: " << arr[index] << endl;

    return 0;
}