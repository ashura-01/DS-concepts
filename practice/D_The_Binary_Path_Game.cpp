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
    string str;
    cin >> n >> str;

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] != str[i + 1])
        {
            count++;
        }
    }

    int moves = n - count - 1;
    
    if (moves % 2 == 0)
    {
        cout << "Uttu" << endl;
    }
    else
    {
        cout << "JJ" << endl;
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