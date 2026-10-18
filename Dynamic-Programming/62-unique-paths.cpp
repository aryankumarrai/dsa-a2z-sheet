/*
Problem: Unique Paths
Reference: https://leetcode.com/problems/unique-paths/
Difficulty: Medium


Time Complexity: O(m+n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalSteps = m + n - 2;
        int downSteps = min(m - 1, n - 1);
        
        long long res = 1;
        int j = 1; // Tracks the denominator division step
        
        // Loop runs exactly (m + n - 2) times -> O(m + n) time
        for (int i = 1; i <= totalSteps; i++) {
            // Include the numerator terms (numbers greater than the max subset)
            if (i > totalSteps - downSteps) {
                res *= i;
            }
            
            // Proactively divide out denominator elements when safely divisible
            if (j <= downSteps && res % j == 0) {
                res /= j;
                j++;
            }
        }
        
        return (int)res;
    }
};

