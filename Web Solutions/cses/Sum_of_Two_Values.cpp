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

void solveProblem()
{
    // Your problem-solving code here
    int n, x;
    cin >> n >> x;

    map<int, int> mp;

    for (size_t i = 1; i <= n; i++)
    {
        int elem;
        cin >> elem;

        int det = x - elem;

        if (mp.count(det))
        {
            cout << mp[det] << " " << i << endl;
            return;
        }
        else
        {
            mp[elem] = i;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solveProblem();
    }

    return 0;
}