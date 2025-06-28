#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define write cout <<
#define nl << endl

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solveProblem()
{
    // Your problem-solving code here
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desire(n);
    vector<int> apartments(m);

    for (auto &elem : desire)
        cin >> elem;
    for (auto &elem : apartments)
        cin >> elem;

    sort(all(desire));
    sort(all(apartments));

    int i = 0;
    int j = 0;
    int count = 0;

    while (i < n && j < m)
    {
        int kCheck = abs(desire[i] - apartments[j]);

        if (kCheck <= k)
        {
            count++;
            i++;
            j++;
        }
        else if (desire[i] > apartments[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    write count nl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solveProblem();
    }

    return 0;
}



// Input:

// makefile
// Copy
// Edit
// n = 4, m = 3, k = 5  
// Desires:     60 45 80 60  
// Apartments:  30 60 75
// Sorted:

// makefile
// Copy
// Edit
// Desires:     45 60 60 80  
// Apartments:  30 60 75
// Try matching:
// 45 & 30 → ❌ 30 too small
// 45 & 60 → ❌ 60 too big
// 60 & 60 → ✅ match → count = 1
// 60 & 75 → ❌ too big
// 80 & 75 → ✅ match → count = 2

// ✅ Answer = 2