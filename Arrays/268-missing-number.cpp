/*
Problem: Missing Number
Reference: https://leetcode.com/problems/missing-number/
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
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int val = 0;
        for (int i = 1; i <= n; i++)
        {
            val += i;
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        return val - sum;
    }
};