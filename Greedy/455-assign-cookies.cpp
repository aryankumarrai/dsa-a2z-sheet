/*
Problem: Assign Cookies
Reference: https://leetcode.com/problems/assign-cookies/
Difficulty: Easy


Time Complexity: O(nlog(n)+mlog(m))
Space Complexity: O(log(n)+log(m))
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int co = 0;
        int ch = 0;
        while (co < s.size() && ch < g.size())
        {
            if (s[co] >= g[ch])
            {
                ch++;
            }
            co++;
        }
        return ch;
    }
};