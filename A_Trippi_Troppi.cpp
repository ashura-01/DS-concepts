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
    
    string str;
    getline(cin, str);

    string result;
    result.push_back(str[0]);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            result.push_back(str[i + 1]);
        }
    }

    cout << result << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        solveProblem();
    }

    return 0;
}