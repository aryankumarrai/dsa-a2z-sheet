/*
Problem: Longest Palindromic Substring
Reference: https://leetcode.com/problems/longest-palindromic-substring/
Difficulty: Medium


Time Complexity: O(n*n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s;
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            int l = i;
            int r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                l--;
                r++;
            }
            if (r - l - 1 > res.size())
            {
                res = s.substr(l + 1, r - l - 1);
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                l--;
                r++;
            }
            if (r - l - 1 > res.size())
            {
                res = s.substr(l + 1, r - l - 1);
            }
        }
        return res;
    }
};