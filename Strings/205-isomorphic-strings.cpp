/*
Problem: Isomorphic Strings
Reference: https://leetcode.com/problems/isomorphic-strings/
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
    bool isIsomorphic(string s, string t)
    {
        int m1[256] = {0};
        int m2[256] = {0};
        int sz = s.size();
        for (int i = 0; i < sz; i++)
        {
            if (m1[s[i]] != m2[t[i]])
            {
                return 0;
            }
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return 1;
    }
};