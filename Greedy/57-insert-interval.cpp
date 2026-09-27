/*
Problem: Insert Interval
Reference: https://leetcode.com/problems/insert-interval/
Difficulty: Medium


Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};