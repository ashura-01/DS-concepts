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

int recur(int i, int w, int n, vector<int> &vrr, vector<int> &wrr, vector<vector<int>> &arr)
{
    if (i == n)
        return 0;

    // step-01: if already exits
    if (arr[i][w] != -1)
    //step -02: then return the value
        return arr[i][w];

    // not take case
    int nottake = recur(i + 1, w, n, vrr, wrr, arr);

    // valid take case
    int take = INT_MIN;
    if (wrr[i] <= w)
    {
        take = vrr[i] + recur(i + 1, w - wrr[i], n, vrr, wrr, arr);
    }
    // step -03: the update the value
    return arr[i][w] = max(take, nottake);
}

void solveProblem()
{
    // Your problem-solving code here
    int n, w;
    cin >> n >> w;
    vector<int> vrr(n);
    vector<int> wrr(n);

    for (int i = 0; i < n; i++)
        cin >> wrr[i] >> vrr[i];

    vector<vector<int>> arr(n + 1, vector<int>(w + 1, -1));

    int ans = recur(0, w, n, vrr, wrr, arr);

    cout << ans << endl;
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