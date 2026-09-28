/*
Problem: Merge Intervals
Reference: https://leetcode.com/problems/merge-intervals/
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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for (auto i : intervals)
        {
            if (i[0] <= temp[1])
            {
                temp[1] = max(i[1], temp[1]);
            }
            else
            {
                res.push_back(temp);
                temp = i;
            }
        }
        res.push_back(temp);
        return res;
    }
};