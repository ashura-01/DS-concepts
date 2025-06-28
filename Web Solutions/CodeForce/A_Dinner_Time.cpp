#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solveProblem()
{
    // Your problem-solving code here
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    int unit = n / p;

    if (n % p == 0)
    {
        if (unit * q == m)
            cy;
        else
            cn;
    }
    else
        cy;
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