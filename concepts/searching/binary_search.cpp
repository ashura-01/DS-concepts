#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int binarySearch(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void output(vector<int> &arr)
{
    for (int i =0; i<arr.size(); i++)
    {
        cout<<arr[i]<<endl;
    }
}

int32_t main()
{
   
    vector<int> arr(10);

    for (int i = 0; i < 10; i++)
    {
        cout << "enter elements: ";
        cin >> arr[i];
    }

    cout << "enter target" << endl;
    int target;
    cin >> target;

    // sort(all(arr));
    sort(arr.begin(), arr.end());
    output(arr);
    int location = binarySearch(arr, target);

    cout<<"the target is at the locatin: " << location<<endl;

    return 0;
}