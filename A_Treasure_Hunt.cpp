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
    int b, k, a;
    cin >> b >> k >> a;

    int mod = a % (b + k);

    if (mod < b)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    // int totalwork = 0;

    // for (int i = 1;; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         totalwork = (i/2)*(b+k);

    //         if ((double)totalwork > (double)a + 0.5)
    //         {
    //             cout << "YES" << endl;
    //             //cout<< totalwork<<endl;
    //             break;
    //         }
    //     }
    //     else
    //     {
    //         totalwork = totalwork + b;
    //         if ((double)totalwork > (double)a + 0.5)
    //         {
    //             cout << "NO" << endl;
    //             //cout<< totalwork<<endl;

    //             break;
    //         }
    //     }
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