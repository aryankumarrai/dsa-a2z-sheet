/*
Problem: String to Integer (atoi)
Reference: https://leetcode.com/problems/string-to-integer-atoi/
Difficulty: Medium


Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using ll = long long;

class Solution
{
public:
    int myAtoi(string s)
    {
        ll maxint = INT_MAX;
        ll minint = INT_MIN;
        int n = s.size();
        int i = 0;
        int sign = 1;
        ll res = 0;
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        if (i == n)
        {
            return 0;
        }
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }
        while (i < n && isdigit(s[i]))
        {
            if (res > maxint)
            {
                if (sign == 1)
                {
                    return maxint;
                }
                return minint;
            }
            res = res * 10 + (s[i] - '0');
            i++;
        }
        res *= sign;
        if (res < minint)
        {
            return minint;
        }
        else if (res > maxint)
        {
            return maxint;
        }
        return res;
    }
};