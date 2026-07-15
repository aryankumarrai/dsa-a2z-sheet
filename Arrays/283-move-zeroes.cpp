/*
Problem: Rotate Array
Reference: https://leetcode.com/problems/move-zeroes
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
    void moveZeroes(vector<int> &nums)
    {
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] != 0)
            {
                swap(nums[r], nums[l]);
                l++;
            }
        }
    }
};