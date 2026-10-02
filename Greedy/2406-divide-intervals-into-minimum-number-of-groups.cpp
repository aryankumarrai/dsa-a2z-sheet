/*
Problem: Divide Intervals Into Minimum Number of Groups
Reference: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
Difficulty: Medium


Time Complexity: O(nlog(n))
Space Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        vector<int> st;
        vector<int> en;
        for (const auto &interval : intervals)
        {
            st.push_back(interval[0]);
            en.push_back(interval[1]);
        }
        sort(st.begin(), st.end());
        sort(en.begin(), en.end());
        int n = st.size();
        int i = 0;
        int j = 0;
        int curr = 0;
        int maxgrp = 0;
        while (i < n)
        {
            if (st[i] <= en[j])
            {
                curr++;
                maxgrp = max(maxgrp, curr);
                i++;
            }
            else
            {
                curr--;
                j++;
            }
        }
        return maxgrp;
    }
};