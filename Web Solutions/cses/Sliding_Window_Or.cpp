#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solveProblem()
{
    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> arr(n);
    arr[0] = x;

    for (int i = 1; i < n; i++) {
        x = (a * x + b) % c;
        arr[i] = x;
    }

    int result = 0;

    for (int i = 0; i <= n - k; i++) {
        int window_or = 0;
        for (int j = i; j < i + k; j++) {
            window_or |= arr[j];
        }
        result ^= window_or;
    }

    cout << result << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solveProblem();
    return 0;
}
