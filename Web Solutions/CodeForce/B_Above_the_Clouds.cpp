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
    string s;
    cin >> n >> s;

    bool ok = false;

    for (int i = 1; i < n - 1; i++)
    {
        string a = s.substr(0, i);
        string b = s.substr(i, 1);
        string c = s.substr(i + 1);
        if ((a + c).find(b) != string::npos)
        {
            ok = true;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
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