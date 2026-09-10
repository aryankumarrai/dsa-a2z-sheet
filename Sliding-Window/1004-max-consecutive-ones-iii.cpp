/*
Problem: Max Consecutive Ones III
Reference: https://leetcode.com/problems/max-consecutive-ones-iii/
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
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;
        int zerocount = 0;
        int maxlen = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
            {
                zerocount++;
            }
            if (zerocount > k)
            {
                if (nums[left] == 0)
                {
                    zerocount--;
                }
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};