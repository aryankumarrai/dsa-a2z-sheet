/*
Problem: Single Element in a Sorted Array
Reference: https://leetcode.com/problems/single-element-in-a-sorted-array
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
    int singleNonDuplicate(vector<int> &nums)
    {
        int st = 0, end = nums.size() - 1;
        if (nums.size() == 1)
        {
            return nums[0];
        }
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (mid == 0 && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            if (mid == nums.size() - 1 && nums[mid] != nums[mid - 1])
            {
                return nums[mid];
            }
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid - 1])
                {
                    end = mid - 1;
                }
                else
                {
                    st = mid + 1;
                }
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                {
                    st = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return 0;
    }
};