/*
Problem: Best Time to Buy and Sell Stock
Reference: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
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
    int maxProfit(vector<int> &prices)
    {
        int mp = 0;
        int bb = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > bb)
            {
                mp = max(mp, prices[i] - bb);
            }
            bb = min(bb, prices[i]);
        }
        return mp;
    }
};