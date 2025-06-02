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
    sort(arr.begin(), arr.end());
    int len = arr.size();
    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
            return {i, j};
        }

        else if (sum < target)
        {
            i++;
        }

        else
        {
            j--;
        }
    }
    return {-1,-1};
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