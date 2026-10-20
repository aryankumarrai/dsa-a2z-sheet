/*
Problem: Unique Paths II
Reference: https://leetcode.com/problems/unique-paths-ii/
Difficulty: Medium


Time Complexity: O(m*n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // Returns the number of paths with one-dimensional storage.
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> dp(cols, 0);

        // Processes rows while reusing the same column states.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Clears every blocked column state.
                if (grid[row][col] == 1) {
                    dp[col] = 0;
                    continue;
                }

                // Initializes the only path at the starting cell.
                if (row == 0 && col == 0) {
                    dp[col] = 1;
                    continue;
                }

                int fromAbove = dp[col];
                int fromLeft = 0;

                // Reads the active-row value from the left.
                if (col > 0) {
                    fromLeft = dp[col - 1];
                }

                // Calculates current from above and left.
                int current = fromAbove + fromLeft;

                // Shifts the column state to the active row.
                dp[col] = current;
            }
        }

        return dp[cols - 1];
    }
};