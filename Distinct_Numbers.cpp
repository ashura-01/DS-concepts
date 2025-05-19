#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void solveProblem(vector<int> &arr)
{
    map<int , int> frequency;

    for (int elem : arr)
    {
        frequency[elem]++;
    }

    int min = INT_MAX;

    for (auto [key , value]: frequency)
    {
        if(min>value) min = value;
    }

    // cout<<min<<endl;
    
    cout<< frequency.size()<<endl;
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    

    int t = 1;
  
    while (t--)
    {
        solveProblem(arr);
    }

    return 0;
}