#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define write cout <<
#define nl << endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solveProblem()
{
    // Your problem-solving code here
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desire(n);
    vector<int> apartments(m);

    for (auto &elem : desire)
        cin >> elem;
    for (auto &elem : apartments)
        cin >> elem;

    sort(all(desire));
    sort(all(apartments));

    int i = 0;
    int j = 0;
    int count = 0;

    while (i < n && j < m)
    {
        int kCheck = abs(desire[i] - apartments[j]);

        if (kCheck <= k)
        {
            count++;
            i++;
            j++;
        }
        else if (desire[i] > apartments[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    write count nl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solveProblem();
    }

    return 0;
}