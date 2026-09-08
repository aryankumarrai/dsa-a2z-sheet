/*
Problem: Remove Nth Node From End of List
Reference: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Difficulty: Medium


Time Complexity: O(Sz)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = nullptr;
    }
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode *next)
    {
        val = x;
        next = next;
    }
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Create a dummy node to handle head deletion smoothly
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++)
        {
            if (fast->next == nullptr)
                return head; // Safety check for invalid 'n'
            fast = fast->next;
        }

        // Move both pointers until fast reaches the last node
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // slow->next is the node to be deleted
        ListNode *nodeToDelete = slow->next;
        slow->next = slow->next->next;

        // Free memory to prevent leaks
        delete nodeToDelete;

        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};