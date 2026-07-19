/*
Problem: Max Consecutive Ones
Reference: https://leetcode.com/problems/max-consecutive-ones/
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
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0;
        int temp = 0;
        for (int &i : nums)
        {
            if (i == 1)
            {
                res++;
            }
            else
            {
                temp = max(temp, res);
                res = 0;
            }
        }
        return max(temp, res);
    }
};