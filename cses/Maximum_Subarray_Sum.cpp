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

    int current = arr[0];
    int maxm = arr[0];

    for (int i = 1; i < n; i++)
    {
        int sum = current + arr[i];

        current = max(arr[i], sum);
        maxm = max(current, maxm);
    }

    cout << maxm << endl;
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