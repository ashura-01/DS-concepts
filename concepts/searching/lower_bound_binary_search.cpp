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
        cout << " ";
    cout << "\n";

    for (int i = 0; i < n; ++i)
        cout << "| " << setw(2) << arr[i] << " ";
    cout << "|\n";

    for (int i = 0; i < n; ++i)
        cout << "-----";
    cout << "-\n";
}

int lowerBoundBinarySearch(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int lowerBoundBinarySearch_yo(vector<int> arr, int target)
{
    int low = 0, high = arr.size();

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

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 13, 14, 15};
    print(arr);

    int target = 11;

    int index = lowerBoundBinarySearch_yo(arr, target);

    cout << "the target: " << arr[index] << "---->" << index << endl;

    return 0;
}