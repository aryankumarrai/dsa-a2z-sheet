/*
Problem: Maximum Nesting Depth of the Parentheses
Reference: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
Difficulty: Easy


Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int maxDepth(string s)
    {
        int leftB = 0;
        int rightB = 0;
        int res = 0;
        for (char c : s)
        {
            if (c == '(')
                leftB++;
            else if (c == ')')
                rightB++;
            res = max(res, (leftB - rightB));
        }
        return res;
    }
};