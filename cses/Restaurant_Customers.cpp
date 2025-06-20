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
    int n;
    cin >> n;

    map<int, int> mp;
    int maxIndx = 0;

    for (int i = 0; i < n; i++)
    {
        int key, value;
        cin >> key >> value;

        maxIndx = max({maxIndx, key, value});
        mp[key] = value;
    }

    vector<int> arr(maxIndx + 1, 0);

    for (auto [key, value] : mp)
    {
        arr[key] = 1;
        arr[value] = -1;
    }

    int i = 0, sum = 0;
    while (i < arr.size() && arr[i] != -1)
    {
        sum += arr[i];
        i++;
    }

    cout << sum << endl;
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
