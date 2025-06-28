#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solveProblem()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n, 0);

    

    for (int i = 0; i < k; i++)
        arr[i]=1;
   

    for (auto elem : arr)
        cout << elem;

    cout << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solveProblem();
    }

    return 0;
}
