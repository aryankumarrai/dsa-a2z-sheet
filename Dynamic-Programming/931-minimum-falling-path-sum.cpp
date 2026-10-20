/*
Problem: Minimum Falling Path Sum
Reference: https://leetcode.com/problems/minimum-falling-path-sum/
Difficulty: Medium


Time Complexity: O(n*n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // The final row supplies every base-state value.
        vector<int> nextRow = matrix[n - 1];

        // Upward order keeps one complete child row available.
        for (int row = n - 2; row >= 0; row--)
        {
            vector<int> current(n, 0);

            for (int col = 0; col < n; col++)
            {
                int downLeft = 1000000000;
                int down = nextRow[col];
                int downRight = 1000000000;

                // A left diagonal exists beyond the first column.
                if (col > 0)
                {
                    downLeft = nextRow[col - 1];
                }

                // A right diagonal exists before the last column.
                if (col + 1 < n)
                {
                    downRight = nextRow[col + 1];
                }

                // Current uses only the unchanged child row.
                int bestNext = min(
                    downLeft, min(down, downRight));
                current[col] = matrix[row][col] + bestNext;
            }

            // The shift occurs after every current state is ready.
            nextRow = current;
        }

        // The final rolling row stores every starting sum.
        return *min_element(nextRow.begin(), nextRow.end());
    }
};