/*
Problem: Check if Array Is Sorted and Rotated
Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated
Difficulty: Easy

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] < nums[i])
                cnt++;
        }
        if (nums[n - 1] > nums[0])
            cnt++;
        if (cnt == 0 || cnt == 1)
        {
            return 1;
        }
        return 0;
    }
};