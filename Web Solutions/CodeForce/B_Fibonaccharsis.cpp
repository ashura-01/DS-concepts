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

    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        int second = n;
        int first = i;

        bool flag = true;

        for (int j = k - 2; j >= 1; j--)
        {
            int sum = second - first;
            if (sum < 0 || sum > first)
            {
                flag = false;
                break;
            }

            second = first;
            first = sum;
        }

        if (flag)
            ans++;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solveProblem();
    }

    return 0;
}