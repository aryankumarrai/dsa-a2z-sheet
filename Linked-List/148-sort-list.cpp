/*
Problem: Sort List
Reference: https://leetcode.com/problems/sort-list/
Difficulty:Medium


Time Complexity: O(n(log(n)))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution
{
public:
    // Function to merge two sorted linked lists
    ListNode *mergeTwoSortedLinkedLists(ListNode *list1, ListNode *list2)
    {
        // Create a dummy node to act as the head anchor
        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr)
        {
            // Compare value properties instead of data
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // Attach remaining elements
        temp->next = (list1 != nullptr) ? list1 : list2;

        ListNode *sortedHead = dummyNode->next;
        delete dummyNode; // Free the dummy node allocation to prevent memory leaks
        return sortedHead;
    }

    // Function to find the middle node of a linked list
    ListNode *findMiddle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Standard platform entry point function name
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // Locate split boundary
        ListNode *middle = findMiddle(head);

        // Disconnect the left and right fragments
        ListNode *right = middle->next;
        middle->next = nullptr;
        ListNode *left = head;

        // Recursively conquer
        left = sortList(left);
        right = sortList(right);

        // Merge sorted components
        return mergeTwoSortedLinkedLists(left, right);
    }
};