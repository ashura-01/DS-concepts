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
    cin >> str;

    int len = str.size();
    int count = 0;

    int indx;

    for (int i = len - 1; i >= 0; i--)
    {
        int num = str[i] - '0';
        if (num >= 1)
        {
            indx = i;
            break;
        }
        count++;
    }

    for (int i = 0; i < indx; i++)
    {
        if (str[i]!='0')
        {
            count++;
        }
        
    }
    

    cout << count << endl;
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