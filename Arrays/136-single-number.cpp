/*
Problem: Single Number
Reference: https://leetcode.com/problems/single-number/
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
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int val : nums)
        {
            ans ^= val;
        }
        return ans;
    }
};