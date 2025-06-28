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
    int n, count = 1;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        mp[key] = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[i] > mp[i + 1])
        {
            count++;
        }
    }

    cout << count << endl;
}
void solveProblem2()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> pos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    int count = 1;

    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i-1])
        {
            count++;
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
        solveProblem2();
    }

    return 0;
}