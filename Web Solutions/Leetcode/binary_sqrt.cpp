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

int solveProblem(int x)
{
    // Your problem-solving code here
    if (x <= 2)
        return x;

    int low = 0;
    int high = x;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (mid * mid <= x)
        {
            ans = mid;
            low = mid + 1;
        }

        else
            high = mid - 1;
    }

    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout<< solveProblem(8)<<endl;

    return 0;
}