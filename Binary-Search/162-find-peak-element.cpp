/*
Problem: Find Peak Element
Reference: https://leetcode.com/problems/find-peak-element/
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
    int findPeakElement(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int res;
        while (low < high)
        {
            int mid = low + ((high - low)) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};