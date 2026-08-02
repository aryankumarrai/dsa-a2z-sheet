/*
Problem: Binary Search
Reference: https://leetcode.com/problems/binary-search
Difficulty: Easy


Time Complexity: O(log(n))
Space Complexity: O(1)
*/


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};