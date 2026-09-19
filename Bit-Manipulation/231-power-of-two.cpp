/*
Problem: Power of Two
Reference: https://leetcode.com/problems/power-of-two/
Difficulty: Easy


Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && not(n & n - 1);
    }
};