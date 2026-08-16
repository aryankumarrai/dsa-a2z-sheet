/*
Problem: Split Array Largest Sum
Reference: https://leetcode.com/problems/split-array-largest-sum/
Difficulty: Hard


Time Complexity: O(nlog(s))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int checkMaxSum(vector<int> &nums, int sum)
    {
        int split = 1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (ans + nums[i] > sum)
            {
                split++;
                ans = nums[i];
            }
            else
            {
                ans += nums[i];
            }
        }
        return split;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for (int i : nums)
        {
            high += i;
        }
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            int temp = checkMaxSum(nums, mid);
            if (temp <= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};