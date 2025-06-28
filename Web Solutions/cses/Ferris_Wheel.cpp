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
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);

    for (auto &elem : arr)
        cin >> elem;
    sort(all(arr));

    int i = 0;
    int j = arr.size() - 1;
    int count = 0;

    while (i <= j)
    {
        int sum = arr[i] + arr[j];

        if (arr[i] + arr[j] <= x)
        {
            i++;
        }

        j--;
        count++;
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

// n = 4, x = 10
// Weights: 7 2 3 9
// Sorted Weights: 2 3 7 9

// Try pairing lightest and heaviest:

// 2 + 9 = 11 → ❌ too heavy → 9 goes alone → gondola 1

// Try next heaviest: 2 + 7 = 9 → ✅ → gondola 2

// Left with 3 → alone → gondola 3

// ✅ Answer = 3