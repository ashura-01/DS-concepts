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
    string s;
    cin >> s;
    int num = stoi(s);
    
    for (int a = 0; a <= 100; ++a) {
        for (int b = 0; b <= 100; ++b) {
            int sum = a + b;
            if (sum * sum == num) {
                cout << a << " " << b << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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