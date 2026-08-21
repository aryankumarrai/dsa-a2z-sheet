/*
Problem: Remove Outermost Parentheses
Reference: https://leetcode.com/problems/remove-outermost-parentheses/
Difficulty: Easy


Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string res;
        int cnt = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                if (cnt > 0)
                {
                    res += c;
                }
                cnt++;
            }
            else if (c == ')')
            {
                cnt--;
                if (cnt > 0)
                {
                    res += c;
                }
            }
        }
        return res;
    }
};