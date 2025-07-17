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

class Solution {
public:
    int binary(vector<int> &arr, int target, int low, int high)
    {
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

    int findPivot(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        return low; 
    }

    int solve(vector<int> &arr, int target)
    {
        int n = arr.size();
        int pivot = findPivot(arr);

        int left = binary(arr, target, 0, pivot - 1);
        int right = binary(arr, target, pivot, n - 1);

        if (left != -1) return left;
        if (right != -1) return right;
        return -1;
    }
};


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution sol;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int x = 0;

    cout << sol.solve(arr, x) << endl;

    return 0;
}