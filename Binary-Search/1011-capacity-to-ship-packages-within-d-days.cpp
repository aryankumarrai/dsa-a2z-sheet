/*
Problem: Capacity To Ship Packages Within D Days
Reference: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
Difficulty: Medium


Time Complexity: O(nlog(S))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int found(vector<int> &weights, int weight)
    {
        int day = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (load + weights[i] > weight)
            {
                day++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int w : weights)
        {
            high += w;
        }
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (found(weights, mid) <= days)
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