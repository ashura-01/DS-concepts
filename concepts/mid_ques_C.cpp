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

void sort(vector<int> &arr)
{
    int n = arr.size();
    for(int i=0; i<n-1; i++)
    {
        int mindex = i;
        
        for (int j= i+1; j<n; j++)
        {
            if(arr[j]<arr[mindex])
            {
                mindex = j;
            }
        }

        swap(arr[i], arr[mindex]);
    }
}
int medianSearch(vector<int> &arr)
{
    int low = *min(arr.begin(),arr.end());
    int high = *max(arr.begin(), arr.end());
    int n= arr.size();

    while(low<high)
    {
        int mid = low+(high-low)/2;
        int count = 0;
        for(auto elem:arr)
            if(elem<=mid)
                count++;

        if(count>n/2)
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    return low;
}

void solveProblem()
{
    // Your problem-solving code here
    vector<int> arr ={6,4,3,9,6};
    sort(arr);
    int median = medianSearch(arr);
    // cout<<median<<endl;
    int n = arr.size();

    int count = 0;

    for(int i =0; i<n; i++)
    {
        if(arr[i]>median)
        {
            while(arr[i]!=median)
            {
                arr[i]--;
                count++;

            }
        }
        if(arr[i]<median)
        {
            while(arr[i]!=median)
            {
                arr[i]++;
                count++;
            }
        }
    }

    cout<<count<<endl;

}

int32_t main()
{
    solveProblem();

    return 0;
}