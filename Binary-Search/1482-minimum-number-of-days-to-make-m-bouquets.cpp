/*
Problem: Minimum Number of Days to Make m Bouquets
Reference: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
Difficulty: Medium


Time Complexity: O(nlog(d))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    bool possibleBloom(vector<int> &bloomDay, int d, int m, int k)
    {
        int count = 0;
        int b = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= d)
            {
                count++;
            }
            else
            {
                b += count / k;
                count = 0;
            }
        }
        b += count / k;
        if (b >= m)
        {
            return 1;
        }
        return 0;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if ((long long)m * k > (long long)bloomDay.size())
        {
            return -1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (possibleBloom(bloomDay, mid, m, k))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};