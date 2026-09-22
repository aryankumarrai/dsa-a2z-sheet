/*
Problem: Divide Two Integers
Reference: https://leetcode.com/problems/divide-two-integers/
Difficulty: Medium


Time Complexity: O((log(n))^2)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
            return 1;
        bool sign = true;
        if (dividend <= 0 && divisor > 0)
            sign = false;
        if (dividend >= 0 && divisor < 0)
            sign = false;

        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long q = 0;
        while (n >= d)
        {
            int cnt = 0;
            while (n >= (d << (cnt + 1)))
            {
                cnt++;
            }
            q += (1 << cnt);
            n -= (d << cnt);
        }
        if (q == (1 << 31) && sign)
            return INT_MAX;
        if (q == (1 << 31) && !sign)
            return INT_MIN;
        if (sign)
            return q;
        else
            return -q;
    }
};