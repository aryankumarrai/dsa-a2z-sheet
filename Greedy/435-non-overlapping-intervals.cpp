/*
Problem: Non-overlapping Intervals
Reference: https://leetcode.com/problems/non-overlapping-intervals/
Difficulty: Medium


Time Complexity: O(nlog(n))
Space Complexity: O(log(n))
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    static bool comp(vector<int> &first, vector<int> &second)
    {
        return first[1] < second[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), comp);
        int removeCount = 0;
        int lastEndTime = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < lastEndTime)
            {
                removeCount++;
            }
            else
            {
                lastEndTime = intervals[i][1];
            }
        }
        return removeCount;
    }
};