/*
Problem: Find First and Last Position of Element in Sorted Array
Reference: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Difficulty: Medium


Time Complexity: O(log(n))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }

private:
    int findBound(vector<int> &nums, int target, bool isFirst)
    {
        int low = 0;
        int high = nums.size() - 1;
        int res = -1;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (nums[mid] == target)
            {
                res = mid;
                if (isFirst)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if (target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};