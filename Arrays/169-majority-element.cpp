/*
Problem: Majority Element
Reference: https://leetcode.com/problems/majority-element/
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
    int majorityElement(vector<int> &nums)
    {
        int sz = nums.size();
        int frq = 0, ans = 0;
        for (int i = 0; i < sz; i++)
        {
            if (frq == 0)
            {
                ans = nums[i];
            }
            if (ans == nums[i])
            {
                frq++;
            }
            else
            {
                frq--;
            }
        }

        return ans;
    }
};