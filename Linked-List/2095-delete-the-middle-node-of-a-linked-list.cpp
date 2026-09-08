/*
Problem: Delete the Middle Node of a Linked List
Reference: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
Difficulty: Medium


Time Complexity: O(n/2)
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
    ListNode *deleteMiddle(ListNode *head)
    {
        // Base case: If list is empty or has only one node,
        // return nullptr without calling delete on head.
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        // Traverse the list with the fast and slow pointers
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;

        // Safely free the detached middle node
        delete slow;

        return head;
    }
};