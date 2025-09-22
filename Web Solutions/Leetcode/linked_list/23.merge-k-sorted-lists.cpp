/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
/**
  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 */
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
    typedef ListNode node;
public:
    
    node* lastNode(node* root)
    {
        node *curr = root;
        while(curr->next)
        {
            curr = curr->next;
        }

        return curr;
    }
    ListNode *mergeKLists(vector<ListNode *> &arr)
    {
        node *root = nullptr;
        for(auto element:arr)
        {
            if (element==nullptr)
            {
                continue;
            }
            if(root==nullptr)
            {
                root = element;
            }
            else
            {
                node *last = lastNode(root);
                last->next = element;
            }
        }

        return root;
    }
};
// @lc code=end
