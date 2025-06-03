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
    string str;
    cin >> str;

    int count = 0;

    int i = 0;
 
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            count++;
        else if (str[i] == ')')
            count--;

        if (count == 0)
            break;
    }
    if (i == str.length() - 1 && count == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    //     bool flag= true;

    //     while (i < j)
    //     {
    //         if (!(str[i] == '(' && str[j] == ')'))
    //         {
    //             flag = false;
    //             break;
    //         }
    //         i++;
    //         j--;
    //     }

    //    if (flag)
    //    {
    //     cout<<"NO"<<endl;
    //    }
    //    else
    //    {
    //     cout<<"YES"<<endl;
    //    }
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