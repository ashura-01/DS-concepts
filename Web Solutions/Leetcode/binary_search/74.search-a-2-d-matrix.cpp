/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */
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

// @lc code=start
class Solution
{
public:
    bool binarySearch(vector<int> &arr, int target)
    {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return true;

            else if (arr[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &mat, int target)
    {
        int row = mat.size();
        int col = mat[0].size();
        int low = 0;
        int high = row - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (target >= mat[mid][0] && target <= mat[mid][col - 1])
            {

                return binarySearch(mat[mid], target);
            }

            else if (target >= mat[mid][col - 1])
            {
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }

        return false;
    }
};
// @lc code=end
