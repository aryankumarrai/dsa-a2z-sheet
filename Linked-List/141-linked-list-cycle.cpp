/*
Problem: Linked List Cycle
Reference: https://leetcode.com/problems/linked-list-cycle/
Difficulty: Easy


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
    bool hasCycle(ListNode *head)
    {
        // Initialize two pointers, slow and fast,
        // to the head of the linked list
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 2: Traverse the linked list with
        // the slow and fast pointers
        while (fast != nullptr && fast->next != nullptr)
        {
            // Move slow one step
            slow = slow->next;
            // Move fast two steps
            fast = fast->next->next;

            // Check if slow and fast pointers meet
            if (slow == fast)
            {
                return true; // Loop detected
            }
        }

        // If fast reaches the end of the list,
        // there is no loop
        return false;
    }
};