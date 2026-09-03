/*
Problem: Pow(x, n)
Reference: https://leetcode.com/problems/powx-n/
Difficulty: Medium


Time Complexity: O(log(n))
Space Complexity: O(log(n))
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
private:
    // Function to calculate power of 'x' raised to 'n'
    double power(double x, long long n)
    {
        // Base case: anything raised to 0 is 1
        if (n == 0)
            return 1.0;

        // Base case: anything raised to 1 is itself
        if (n == 1)
            return x;

        // If 'n' is even
        if (n % 2 == 0)
        {
            // Recursive call: x * x, n / 2
            return power(x * x, n / 2);
        }
        // If 'n' is odd
        // Recursive call: x * power(x, n-1)
        return x * power(x, n - 1);
    }

public:
    // Function to calculate x raised to n
    double myPow(double x, int n)
    {
        // Cast to long long to safely handle -1 * INT_MIN
        long long num = n;

        // If n is negative
        if (num < 0)
        {
            // Calculate the power of -num and take reciprocal
            return 1.0 / power(x, -num);
        }
        // If n is non-negative
        return power(x, num);
    }
};
