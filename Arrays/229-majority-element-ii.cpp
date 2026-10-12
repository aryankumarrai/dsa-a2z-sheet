/*
Problem: Majority Element II
Reference: https://leetcode.com/problems/majority-element-ii/
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
    vector<int> majorityElement(vector<int> &nums)
    {
        int sz = nums.size();
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        for (int i = 0; i < sz; i++)
        {
            if (nums[i] == candidate1)
            {
                count1++;
            }
            else if (nums[i] == candidate2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                candidate2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < sz; i++)
        {
            if (nums[i] == candidate1)
                count1++;
            else if (nums[i] == candidate2)
                count2++;
        }
        vector<int> result;
        if (count1 > sz / 3)
            result.push_back(candidate1);
        if (count2 > sz / 3)
            result.push_back(candidate2);
        return result;
    }
};
