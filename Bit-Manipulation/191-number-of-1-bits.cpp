/*
Problem: Number of 1 Bits
Reference: https://leetcode.com/problems/number-of-1-bits/
Difficulty: Easy


Time Complexity: O(k)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int hammingWeight(int n)
    {
        int cnt = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
};