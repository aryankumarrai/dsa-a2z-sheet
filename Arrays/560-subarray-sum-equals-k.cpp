/*
Problem: Subarray Sum Equals K
Reference: https://leetcode.com/problems/subarray-sum-equals-k
Difficulty: Medium


Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        count[0] = 1;
        int res = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curr += nums[i];
            int temp = curr - k;
            if (count.count(temp))
                res += count[temp];
            count[curr]++;
        }
        return res;
    }
};