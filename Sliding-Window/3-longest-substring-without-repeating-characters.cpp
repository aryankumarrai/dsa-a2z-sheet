/*
Problem: Longest Substring Without Repeating Characters
Reference: https://leetcode.com/problems/longest-substring-without-repeating-characters/
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
    int lengthOfLongestSubstring(string s)
    {
        vector<int> lastIndex(128, -1);
        int maxsz = 0;
        int lt = 0;
        for (int rt = 0; rt < s.length(); rt++)
        {
            char c = s[rt];
            if (lastIndex[c] >= lt)
            {
                lt = lastIndex[c] + 1;
            }
            lastIndex[c] = rt;
            maxsz = max(maxsz, rt - lt + 1);
        }
        return maxsz;
    }
};