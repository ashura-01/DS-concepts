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
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(all(arr), [](auto &x, auto &y)
         { return x.second < y.second; });

    int count = 0, current_end = 0;

    for (auto elem : arr)
    {
        if (elem.first >= current_end)
        {
            count++;

            current_end = elem.second;
        }
    }

    cout << count << endl;
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