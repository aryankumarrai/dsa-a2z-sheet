/*
Problem: Climbing Stairs
Reference: https://leetcode.com/problems/climbing-stairs/
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
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;
        int a = 1;
        int b = 1;
        for (int i = 2; i <= n; i++)
        {
            int s = a + b;
            a = b;
            b = s;
        }
        return b;
    }
};