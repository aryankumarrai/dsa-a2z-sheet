/*
Problem: Maximum Subarray
Reference: https://leetcode.com/problems/maximum-subarray/
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
    int maxSubArray(vector<int> &nums)
    {
        int sz = nums.size();
        int cs = 0;
        int ms = INT_MIN;
        for (int i = 0; i < sz; i++)
        {
            cs += nums[i];
            ms = max(cs, ms);
            if (cs < 0)
            {
                cs = 0;
            }
        }
        return ms;
    }
};