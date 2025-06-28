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

vector<int> prefixSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0]+1;

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
        cout << prefix[i] << endl;
    }
    return prefix;
}

void solveProblem2()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &elem : arr)
        cin >> elem;

    sort(all(arr));
    vector<int> prefix = prefixSum(arr);

    int i = 0;
    int j = 0;

    while (i != n && j != n)
    {
        if (prefix[i] > arr[j])
        {
            break;
        }
        else
        {
            i++;
            j++;
        }
    }

    cout << prefix[i] << endl;
}

void solveProblem()
{
    // Your problem-solving code here
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &elem : arr)
        cin >> elem;

    sort(all(arr));

    int target = 1;
    int sum = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= sum)
        {
            sum += arr[i];
        }
        else
        {
            break;
        }
    }
    cout << sum << endl;
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