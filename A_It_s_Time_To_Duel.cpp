#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solveProblem()
{
    // Your problem-solving code here
    int n;
    cin >> n;
    vector<int> arr(n);

    int zero = 0;
    int one = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            zero++;
        }
        else
        {
            one++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] == 0 && arr[i + 1] == 0) || zero == 0 || one == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;

    // if (n % 2 == 0 && zero % 2 != 0 || (n % 2 != 0 && zero % 2 == 0))
    // {
    //     cout << "NO" << endl;
    // }
    // else
    // {
    //     cout << "YES" << endl;
    // }
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