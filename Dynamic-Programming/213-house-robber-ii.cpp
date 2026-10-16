/*
Problem: House Robber II
Reference: https://leetcode.com/problems/house-robber-ii/
Difficulty: Medium


Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
private:
    int robLinear(vector<int> &nums, int start, int end)
    {
        int secondPrevious = 0;
        int previous = nums[start];

        for (int i = start + 1; i <= end; i++)
        {
            int take = nums[i] + secondPrevious;
            int skip = previous;
            int current = max(take, skip);

            secondPrevious = previous;
            previous = current;
        }
        return previous;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        int option1 = robLinear(nums, 0, n - 2);
        int option2 = robLinear(nums, 1, n - 1);
        return max(option1, option2);
    }
};
