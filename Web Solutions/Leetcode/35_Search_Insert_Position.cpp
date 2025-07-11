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
    // Your problem-solving code here
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

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr = {1, 3, 5, 6};
    int target = 2;

    cout << "your target is at: " << solveProblem(arr, target);

    return 0;
}