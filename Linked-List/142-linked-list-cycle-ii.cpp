/*
Problem: Linked List Cycle II
Reference: https://leetcode.com/problems/linked-list-cycle-ii/
Difficulty: Medium


Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        // Traverse until fast and fast->next are not null
        while (fast != NULL && fast->next != NULL)
        {
            // Move slow by one step
            slow = slow->next;

            // Move fast by two steps
            fast = fast->next->next;

            // If they meet, loop is detected
            if (slow == fast)
            {
                // Reset slow to head
                slow = head;

                // Move both one step at a time to find starting point
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};