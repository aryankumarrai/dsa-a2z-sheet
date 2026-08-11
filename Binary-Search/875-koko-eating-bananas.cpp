/*
Problem: Koko Eating Bananas
Reference: https://leetcode.com/problems/koko-eating-bananas/
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
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low < high)
        {
            int mid = low + ((high - low) / 2);
            long long total_hrs = 0;
            for (int p : piles)
            {
                total_hrs += (p + mid - 1) / mid;
            }
            if (total_hrs <= h)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
                ;
            }
        }
        return low;
    }
};