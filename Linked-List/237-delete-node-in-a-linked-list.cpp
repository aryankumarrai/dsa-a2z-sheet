/*
Problem: Delete Node in a Linked List
Reference: https://leetcode.com/problems/delete-node-in-a-linked-list/
Difficulty: Medium


Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // Step 1: Store a reference to the next node
        ListNode *nextNode = node->next;

        // Step 2: Copy the value of the next node into this node
        node->val = nextNode->val;

        // Step 3: Link this node to skip the next node
        node->next = nextNode->next;

        // Step 4: Clear the duplicate node from memory
        delete nextNode;
    }
};