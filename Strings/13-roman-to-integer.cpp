/*
Problem: Roman to Integer
Reference: https://leetcode.com/problems/roman-to-integer/
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
    int romanToInt(string s)
    {
        int res = 0;
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (roman[s[i]] < roman[s[i + 1]])
            {
                res -= roman[s[i]];
            }
            else
            {
                res += roman[s[i]];
            }
        }
        return res + roman[s.back()];
    }
};