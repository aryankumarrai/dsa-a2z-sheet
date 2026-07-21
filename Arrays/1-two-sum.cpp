/*
Problem: Two Sum
Reference: https://leetcode.com/problems/two-sum
Difficulty: Easy


Time Complexity: O(n)
Space Complexity: O(n)
*/


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> check;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (check.count(temp))
            {
                return {check[temp], i};
            }
            check[nums[i]] = i;
        }
        return {};
    }
};