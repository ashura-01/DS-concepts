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

int solveProblem2(map<int, int> &mp, int n)
{
    int count = 1;
    for (int i = 2; i <= n; i++)
    {
        if (mp[i] < mp[i - 1])
            count++;
    }
    return count;
}

void solveProblem1()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    map<int, int> mp;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    vector<pair<int, int>> terms(m);

    for (int i = 0; i < m; i++)
    {
        cin >> terms[i].first >> terms[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        int val1 = arr[terms[i].first];
        int val2 = arr[terms[i].second];

        swap(arr[terms[i].first], arr[terms[i].second]);

        mp[val1] = terms[i].second;
        mp[val2] = terms[i].first;

        int count = solveProblem2(mp, n);
        cout << count << endl;
    }
}

int countDetector(vector<int> &arr, vector<int> &pos)
{

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        pos[arr[i]] = i;
    }
    int count = 1;

    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
        {
            count++;
        }
    }
    return count;
}

void solveProblem()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> pos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    int count = countDetector(arr, pos);

    set<pair<int, int>> sett;

    for(int i = 0; i<m; i++)
    {
        int x,  y;
        cin>>x>>y;
        
    }
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
        solveProblem1();
    }

    return 0;
}
