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
    int n;
    cin >> n;

    vector<int> arr(n * n);
    vector<int> result;
    set<int> sett;

    for (auto &element : arr)
        cin >> element;

    for (auto elem : arr)
    {
        if (sett.insert(elem).second)
            result.push_back(elem);
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        if (!sett.count(i))
            result.insert(result.begin(), i);
    }

    for (auto elem : result)
        cout << elem << " ";
    cout << endl;
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