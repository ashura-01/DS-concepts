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

int recurFibo(vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
        return n;

    if (arr[n] != -1)
        return arr[n];

    arr[n] = recurFibo(arr, n - 1) + recurFibo(arr, n - 2);
    return arr[n];
}

int fib_meno(vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
        return n;

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int fibTebu(vector<int> arr, int n)
{
    if (n == 0 || n == 1)
        return n;
    int a = 0;
    int b= 1;

     for (int i = 2; i <= n; i++)
    {
        int c = a+b;
        a=b;
        b=c;
    }

    return b;

}

void solveProblem()
{
    int n;
    cin >> n;

    vector<int> arr(n + 1, -1);

    // cout << "your output is: " << recurFibo(arr, n) << endl;

    cout << arr[n] << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solveProblem();
    }

    return 0;
}
