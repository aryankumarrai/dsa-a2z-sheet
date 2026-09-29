/*
Problem: Valid Parenthesis String
Reference: https://leetcode.com/problems/valid-parenthesis-string/
Difficulty: Medium


Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int low = 0, high = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                low++;
                high++;
            }
            else if (c == ')')
            {
                low--;
                high--;
            }
            else if (c == '*')
            {
                low--;
                high++;
            }
            if (high < 0)
                return 0;
            low = max(low, 0);
        }
        if (low == 0)
            return 1;
        return 0;
    }
};