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

    vector<int> arr(n);
    for (auto &elem : arr)
        cin >> elem;

    set<int> sett;
    int j = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        while (sett.count(arr[i]))
        {
            sett.erase(arr[j]);
            j++;
        }

        sett.insert(arr[i]);
        count = max(count, i - j + 1);
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