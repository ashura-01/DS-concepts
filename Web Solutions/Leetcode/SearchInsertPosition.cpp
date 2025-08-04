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
    // code starting from here
    int solve(vector<int> &arr, int target)
    {
        int low = 0;
        int high = arr.size();

        while(low<high)
        {
            int mid = (low+high)/2;
            if(arr[mid]<target)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution sol;
    vector<int> arr={-1,0,2,4,6,8};
    int x=5;

    cout << sol.solve(arr,x) << endl;

    return 0;
}