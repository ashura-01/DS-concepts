// two sum target is 42 of a array now check if it maches the target

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << i << ". enter: ";
        cin >> arr[i];
    }
}

vector<int> solveProblem(vector<int> &arr, int target)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < arr.size(); i++)
    {
        int remainder = target - arr[i];

        if (freq.count(remainder))
        {
            return {freq[remainder], i};
        }
        else
        {
            freq[arr[i]] = i;
        }
    }
    return {};
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int size;
    cout << "enter the size: ";
    cin >> size;

    int target;
    cout << "enter the target: ";
    cin >> target;

    vector<int> arr(size);
    input(arr);

    solveProblem(arr, target);

    return 0;
}