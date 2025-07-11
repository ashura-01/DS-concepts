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
    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> arr;
    arr.push_back(x); // Add the first element

    // Generate the rest of the array
    for (int i = 1; i < n; i++)
    {
        x = (a * x + b) % c;
        arr.push_back(x);
    }

    deque<int> dq;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && arr[dq.back()] >= arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        if (i >= k - 1)
            ans ^= arr[dq.front()];
    }

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