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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    int maxGoodPairs = n / 2;

    if (k > maxGoodPairs)
    {
        cout << "NO" << endl;
        return;
    }

    int one = 0;
    int zero = 0;

    for (char ch : str)(ch == '0')? zero++:one++;
    

    int minGoodPairs = abs(one - zero) / 2;

    if (minGoodPairs>k)
    {
        cout << "NO" << endl;
    }
    else if ((k % 2 != 0 && minGoodPairs % 2 != 0)|| (k % 2 == 0 && minGoodPairs % 2 == 0))
    {
        cout << "YES" << endl;
    }
   
    else if (k == minGoodPairs)
    {
        cout << "YES" << endl;
    }

    else
    {
        cout << "NO" << endl;
    }
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