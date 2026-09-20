/*
Problem: PMinimum Bit Flips to Convert Number
Reference: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
Difficulty: Easy


Time Complexity: O(log(n))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int count = 0;
        int ans = start ^ goal;
        while (ans != 0)
        {
            if (ans % 2 == 1)
            {
                count++;
            }
            ans = ans / 2;
        }
        return count;
    }
};