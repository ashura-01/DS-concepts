#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

vector<int> calcPrefixSum(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> sum(n);
    sum[0] = arr[0];
    for (auto i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    return sum;
}

void solveProblem()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefisxum = calcPrefixSum(arr);

    for(auto elem : prefisxum)
    {
        cout<< elem<< " ";
    }
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