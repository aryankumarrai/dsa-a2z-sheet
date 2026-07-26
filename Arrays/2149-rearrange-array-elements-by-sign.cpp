/*
Problem: Rearrange Array Elements by Sign
Link: https://leetcode.com/problems/rearrange-array-elements-by-sign
Difficulty: Medium

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> res(nums.size());
        int pi = 0;
        int ni = 1;
        for (int i : nums)
        {
            if (i > 0)
            {
                res[pi] = i;
                pi += 2;
            }
            if (i < 0)
            {
                res[ni] = i;
                ni += 2;
            }
        }
        return res;
    }
};