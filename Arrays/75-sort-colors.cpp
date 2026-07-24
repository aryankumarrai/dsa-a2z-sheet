/*
Problem: Sort Colors
Reference: https://leetcode.com/problems/sort-colors/
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
    void sortColors(vector<int> &nums)
    {
        int count[3] = {0, 0, 0};
        for (int i : nums)
        {
            count[i]++;
        }
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (count[temp] == 0)
            {
                temp++;
            }
            nums[i] = temp;
            count[temp]--;
        }
    }
};