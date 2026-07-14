/*
Problem: Rotate Array
Reference: https://leetcode.com/problems/rotate-array/
Difficulty: Medium


Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    void reverse(vector<int> &nums, int k, int l)
    {
        int st = k;
        int end = l;
        while (st < end)
        {
            int temp = nums[st];
            nums[st] = nums[end];
            nums[end] = temp;
            st++;
            end--;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};