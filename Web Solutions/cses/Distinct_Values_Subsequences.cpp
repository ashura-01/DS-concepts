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
    vector<int> a(n);
    unordered_map<int, int> freq;
 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }
 
    long long result = 1;
    for (auto &[val, f] : freq) {
        result = (result * (f + 1)) % MOD;
    }
 
    // Exclude empty subsequence
    result = (result - 1 + MOD) % MOD;
 
    cout << result << endl;
    
    
    
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