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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int temp1 = min(a, c);
    int temp2 = min(b, d);

    if (temp1 >= temp2)
    {
        cout << "Gellyfish" << endl;
    }
    
    else
    {
        cout << "Flower" << endl;
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