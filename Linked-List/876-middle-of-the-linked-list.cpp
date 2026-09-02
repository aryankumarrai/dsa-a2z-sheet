/*
Problem: Middle of the Linked List
Reference: https://leetcode.com/problems/middle-of-the-linked-list/
Difficulty: Easy


Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct ListNode {
    public:
        int val;
        ListNode *next;
        ListNode() {
            val = 0;
            next = nullptr;
        }
        ListNode(int x) {
            val = x;
            next = nullptr;
        }
        ListNode(int x, ListNode *next) {
            val = x;
            next = next;
        }
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        // Move fast by 2 steps and slow by 1 step
        // fast must not be null, and fast->next must not be null
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // 1 step
            fast = fast->next->next; // 2 steps
        }

        // slow is now pointing to the middle node
        return slow;
    }
};