/*
Problem: Find Minimum in Rotated Sorted Array
Reference: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
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
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else if (nums[mid] < nums[high])
            {
                high = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return nums[low];
    }
};