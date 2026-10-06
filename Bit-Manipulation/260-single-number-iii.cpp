/*
Problem: Single Number III
Reference: https://leetcode.com/problems/single-number-iii/
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
    vector<int> singleNumber(vector<int> &arr)
    {
        int xorResult = 0;

        /*
         * Duplicate pairs cancel, leaving the XOR
         * of the two values that appear only once.
         */
        for (int num : arr)
        {
            xorResult ^= num;
        }

        /*
         * Use unsigned arithmetic to safely isolate a set bit,
         * including the sign bit when negative values are present.
         */
        uint32_t bits = static_cast<uint32_t>(xorResult);
        uint32_t mask = bits & (~bits + 1u);

        int group1 = 0;
        int group2 = 0;

        /*
         * The chosen bit differs between the two unique values.
         * Equal pairs enter the same group and cancel there.
         */
        for (int num : arr)
        {
            if ((static_cast<uint32_t>(num) & mask) != 0)
            {
                group1 ^= num;
            }
            else
            {
                group2 ^= num;
            }
        }

        return {group1, group2};
    }
};