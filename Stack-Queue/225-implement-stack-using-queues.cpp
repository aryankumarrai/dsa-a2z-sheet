/*
Problem: Implement Stack using Queues
Reference: https://leetcode.com/problems/implement-stack-using-queues/
Difficulty: Easy


Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class MyStack
{
private:
    queue<int> q; // Declared as a member variable so all methods can access it

public:
    // Constructor (can remain empty now since the queue is automatically initialized)
    MyStack()
    {
    }

    // Push element x onto stack
    void push(int x)
    {
        int s = q.size();
        q.push(x);

        // Move elements before the new element to the back
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack and returns it
    int pop()
    {
        int n = q.front();
        q.pop();
        return n;
    }

    // Get the top element
    int top()
    {
        return q.front();
    }

    // Returns whether the stack is empty
    bool empty()
    {
        return q.empty();
    }
};