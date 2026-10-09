/*
Problem: Subarrays with K Different Integers
Reference: https://leetcode.com/problems/subarrays-with-k-different-integers/
Difficulty: Hard


Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
private:
    // Helper function to find subarrays with AT MOST 'goal' distinct integers
    int atMostK(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;

        unordered_map<int, int> mpp;
        int l = 0, r = 0, count = 0;
        int n = nums.size();

        while (r < n)
        {
            mpp[nums[r]]++;

            // If window has more distinct elements than the goal, shrink from left
            while (mpp.size() > goal)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // Exactly(K) = AtMost(K) - AtMost(K - 1)
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};