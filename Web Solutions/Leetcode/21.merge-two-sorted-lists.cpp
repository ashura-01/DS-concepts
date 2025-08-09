/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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

//   Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *sort(ListNode *root)
    {
        for (ListNode *i = root; i != nullptr; i = i->next)
        {
            ListNode *min = i;
            for (ListNode *j = i->next; j != nullptr; j = j->next)
            {
                if (min->val > j->val)
                {
                    min = j;
                }
            }

            swap(i->val, min->val);
        }

        return root;
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return sort(list2); // if list1 is empty, just sort list2
        if (!list2)
            return sort(list1); // if list2 is empty, just sort list1
            
        ListNode *curr1 = list1;

        while (curr1->next != nullptr)
        {
            curr1 = curr1->next;
        }

        curr1->next = list2;

        return sort(list1);
    }
};
// @lc code=end
