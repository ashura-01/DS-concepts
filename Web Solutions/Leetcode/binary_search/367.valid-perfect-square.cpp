/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
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
    bool binsquare(int x)
    {
        int low = 0;
        int high = x;
        int ans = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (1LL*mid * mid <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return (ans * ans == x) ? true : false;
    }

    bool isPerfectSquare(int num)
    {
        return binsquare(num);
    }
};
// @lc code=end
