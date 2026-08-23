/*
Problem: Longest Common Prefix
Reference: https://leetcode.com/problems/longest-common-prefix/
Difficulty: Easy


Time Complexity: O(s*m)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        sort(strs.begin(), strs.end());
        string frst = strs[0];
        string lst = strs[strs.size() - 1];
        string res = "";
        int minl = min(frst.size(), lst.size());
        for (int i = 0; i < minl; i++)
        {
            if (frst[i] != lst[i])
            {
                break;
            }
            res += frst[i];
        }
        return res;
    }
};