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

void solveProblemTLE()
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

void solveProblem()
{
    int n;
    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int key1, key2;
        cin >> key1 >> key2;

        mp[key1]++;
        mp[key2]--;
    }

    int prefixSum = 0;
    int result = 0;

    for (auto values : mp)
    {
        prefixSum += values.second;
        result = (result > prefixSum) ? result : prefixSum;
    }

    cout << result << endl;
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
