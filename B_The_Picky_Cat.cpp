#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solveProblem()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int value;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = abs(arr[i]);
    }

    value = arr[0]; 

    sort(arr.begin(), arr.end());

    bool flag = false;
    for (int i = 0; i <= (n - 1) / 2; i++) 
    {
        if (arr[i] == value)
        {
            flag = true;
            break;
        }
    }

    if (flag || (n % 2 == 0 && arr[n / 2] == value)) 
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

    int t;
    cin >> t;
    while (t--)
    {
        solveProblem();
    }

    return 0;
}
