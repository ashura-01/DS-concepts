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

class Solution
{
public:
    int upper(vector<int> &arr, int target)
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

        if (low > 0 && arr[low - 1] == target)
            return low - 1;
        else
            return -1;
    }

    int lower(vector<int> &arr, int target)
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
        if (low < arr.size() && arr[low] == target)
            return low;
        else
            return -1;
    }

    vector<int> searchRange(vector<int> &arr, int target)
    {
        int low = lower(arr, target);
        int up = upper(arr, target);

        vector<int> ans;
        ans.push_back(low);
        ans.push_back(up);

        return ans;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution sol;
    vector<int> arr;
    int x;

    // cout << sol.solve() << endl;

    return 0;
}