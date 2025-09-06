/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    int len(node *root)
    {
        node *curr = root;
        int count = 0;
        while (curr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }

    void insert(node *&root, int data)
    {
        node *temp = new node(data);
        if (!root)
        {
            root = temp;
            return;
        }
        node *curr = root;
        while (curr->next)
            curr = curr->next;
        curr->next = temp;
    }

    void reverse(node *curr, node *&revList)
    {
        if (!curr)
            return;
        reverse(curr->next, revList);
        insert(revList, curr->val);
    }

    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        // 1. Build reversed list recursively
        node *rev = nullptr;
        reverse(head, rev);

        // 2. Rebuild manually using weave logic
        node *arr = nullptr;
        int n = len(head);
        int half = n / 2;

        node *first = head;
        node *second = rev;

        for (int i = 0; i < half; i++)
        {
            insert(arr, first->val);
            insert(arr, second->val);
            first = first->next;
            second = second->next;
        }

        // If odd length, add middle element
        if (n % 2 != 0)
        {
            insert(arr, first->val);
        }

        // 3. Copy back into original list
        node *curr = head;
        node *tmp = arr;
        while (curr && tmp)
        {
            curr->val = tmp->val;
            curr = curr->next;
            tmp = tmp->next;
        }
    }
};

// @lc code=end
