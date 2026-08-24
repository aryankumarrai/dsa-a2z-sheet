/*
Problem: Valid Anagram
Reference: https://leetcode.com/problems/valid-anagram/
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
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return 0;
        vector<int> count(26);
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a'] = count[s[i] - 'a'] + 1;
            count[t[i] - 'a'] = count[t[i] - 'a'] - 1;
        }

        for (int c : count)
        {
            if (c != 0)
                return 0;
        }
        return 1;
    }
};