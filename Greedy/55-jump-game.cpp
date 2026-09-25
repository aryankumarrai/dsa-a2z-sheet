/*
Problem: Jump Game
Reference: https://leetcode.com/problems/jump-game/
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
    bool canJump(vector<int> &nums)
    {
        int farthest = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > farthest)
                return 0;
            farthest = max(farthest, i + nums[i]);
            if (farthest >= (nums.size() - 1))
                return 1;
        }
        return 1;
    }
};