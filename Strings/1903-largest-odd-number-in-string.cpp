/*
Problem: Largest Odd Number in String
Reference: https://leetcode.com/problems/largest-odd-number-in-string/
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
    string largestOddNumber(string num)
    {
        int i = num.size() - 1;
        while (i >= 0)
        {
            if ((num[i] % 2) != 0)
            {
                return num.substr(0, i + 1);
            }
            i--;
        }
        return "";
    }
};