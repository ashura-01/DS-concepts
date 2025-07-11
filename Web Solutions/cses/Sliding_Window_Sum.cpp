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
    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> arr;
    arr.push_back(x);  // Add the first element

    // Generate the rest of the array
    for (int i = 1; i < n; i++)
    {
        x = (a * x + b) % c;
        arr.push_back(x);
    }

    int sum = 0;
    int xorr = 0;

    // First window
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    xorr ^= sum;

    // Slide the window
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        xorr ^= sum;
    }

    cout << xorr << endl;
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