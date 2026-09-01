/*
Problem: Design Linked List
Reference: https://leetcode.com/problems/design-linked-list/
Difficulty: Medium


Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class MyLinkedList
{
private:
    struct Node
    {
        int val;
        Node *next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node *head;
    int size;

public:
    MyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;

        Node *curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;

        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *curr = head;
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;

        Node *toDelete;
        if (index == 0)
        {
            toDelete = head;
            head = head->next;
        }
        else
        {
            Node *curr = head;
            for (int i = 0; i < index - 1; i++)
            {
                curr = curr->next;
            }
            toDelete = curr->next;
            curr->next = curr->next->next;
        }

        delete toDelete;
        size--;
    }

    ~MyLinkedList()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};
