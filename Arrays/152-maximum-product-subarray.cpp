/*
Problem: Maximum Product Subarray
Reference: https://leetcode.com/problems/maximum-product-subarray/
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
    long long maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        long long currentMax = nums[0];
        long long currentMin = nums[0];
        long long maxProduct = nums[0];

        for (int i = 1; i < n; i++)
        {
            long long currentValue = nums[i];

            /*
             * Preserve both previous states because
             * a negative value can swap their roles.
             */
            long long previousMax = currentMax;
            long long previousMin = currentMin;

            /*
             * Either start fresh or extend one of
             * the previous product subarrays.
             */
            currentMax = max({currentValue,
                              previousMax * currentValue,
                              previousMin * currentValue});

            currentMin = min({currentValue,
                              previousMax * currentValue,
                              previousMin * currentValue});

            // Record the best product found anywhere so far.
            if (currentMax > maxProduct)
            {
                maxProduct = currentMax;
            }
        }
        return maxProduct;
    }
};