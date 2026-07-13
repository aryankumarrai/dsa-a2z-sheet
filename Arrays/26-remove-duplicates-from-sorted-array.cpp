/*
Problem: Remove Duplicates from Sorted Array
Reference: https://leetcode.com/problems/remove-duplicates-from-sorted-array
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
    int removeDuplicates(vector<int> &nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        nums[k] = nums[nums.size() - 1];
        return k + 1;
    }
};