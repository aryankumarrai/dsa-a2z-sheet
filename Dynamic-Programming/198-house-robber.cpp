/*
Problem: House Robber
Reference: https://leetcode.com/problems/house-robber/
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
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int secondPrevious = 0;
        int previous = nums[0];
        for (int i = 1; i < n; i++)
        {
            int take = nums[i] + secondPrevious;
            int skip = previous;

            int current = max(take, skip);

            secondPrevious = previous;
            previous = current;
        }
        return previous;
    }
};
