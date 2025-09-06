#include<bits/stdc++.h>
using namespace std;
void print(const vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; ++i)
        cout << "-----";
    cout << "-\n";

    for (int i = 0; i < n; ++i)
        cout << "| " << setw(2) << i << " ";
    cout << "|\n";

    for (int i = 0; i < n; ++i)
        cout << " ";
    cout << "\n";

    for (int i = 0; i < n; ++i)
        cout << "| " << setw(2) << arr[i] << " ";
    cout << "|\n";

    for (int i = 0; i < n; ++i)
        cout << "-----";
    cout << "-\n";
}

void selectionSort(vector<int> &arr)
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

int max(vector<int> &arr)
{
    int max = arr[0];
    for(int i=0; i<arr.size();i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

int main()
{
    vector<int> arr = {3,9,2,5,8};
    selectionSort(arr);

    int k=3;
    vector<int> data;

    for(int i = 0; i<=arr.size()-k; i++)
    {
        int sum =0;
        int mx = 0;

        for(int j =0; j<k; j++)
        {
            if(mx < arr[i+j])
            {
                mx = arr[i+j];
            }
            sum = sum+arr[i+j];
        }
        data.push_back(sum-mx);
    }
    cout<<max(data)<<endl;
    return 0;
}