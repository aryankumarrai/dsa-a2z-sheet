/*
Problem: Search in Rotated Sorted Array II
Reference: https://leetcode.com/problems/search-in-rotated-sorted-array-ii
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
    bool search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (nums[mid] == target)
            {
                return 1;
            }
            if (nums[mid] == nums[low] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }
            if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return 0;
    }
};