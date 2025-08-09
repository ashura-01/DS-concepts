/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

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
    typedef ListNode node;

    node *middle(node *root)
    {
        node *fast = root;
        node *slow = root;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    node *reverse(node *root)
    {
        node *prev = nullptr;
        node *curr = root;
        node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(node *root)
    {
        if (!root || !root->next)
            return true;

        node *mid = middle(root);

        node *rev = reverse(mid);

        node *full = root;
        node *halfReversed = rev;

        while (halfReversed != nullptr)
        {
            if (full->val != halfReversed->val)
                return false;

            full = full->next;
            halfReversed = halfReversed->next;
        }

        return true;
    }
};
// @lc code=end
