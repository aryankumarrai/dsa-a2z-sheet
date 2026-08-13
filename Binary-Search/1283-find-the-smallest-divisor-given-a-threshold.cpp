/*
Problem: Find the Smallest Divisor Given a Threshold
Reference: hhttps://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
Difficulty: Medium


Time Complexity: O(nlog(m))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low < high)
        {
            int mid = low + ((high - low) / 2);
            long long totalSum = 0;
            for (int i : nums)
            {
                totalSum += (i + mid - 1) / mid;
            }
            if (totalSum <= threshold)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};