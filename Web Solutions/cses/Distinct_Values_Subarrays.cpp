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
    cin >> n;
    vector<int> arr(n);

    for (auto &elem : arr)
        cin >> elem;

    int count = 0;
    int i = 0;
    int j = 0;

    unordered_map<int, int> freq;

    for (i = 0; i < n; i++)
    {
        freq[arr[i]]++;

        while (freq[arr[i]] > 1)
        {
            freq[arr[j]]--;
            j++;
        }

        count+= abs(i-j+1);
    }

    cout << count << endl;
}

void solveProblem1()
{
    // Your problem-solving code here
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &elem : arr)
        cin >> elem;

    int i = 0;
    int j = 0;

    set<int> subarr;
    int count = 0;

    while (i < n)
    {
        while (j < n && !subarr.count(arr[j]))
        {
            subarr.insert(arr[j]);
            j++;
        }
        subarr.erase(arr[i]);
        count += abs(i - j);
        i++;
    }

    cout << count << endl;
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