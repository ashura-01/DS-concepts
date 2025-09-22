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
    int findMin(vector<int> &arr)
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
        return arr[low];
    }
};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution sol;
    vector<int> arr = {3,4,5,6,7,0,1,2};
    int x;

    cout << sol.findMin(arr) << endl;

    return 0;
}