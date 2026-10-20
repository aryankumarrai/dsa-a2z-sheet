/*
Problem: Triangle
Reference: https://leetcode.com/problems/triangle/
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
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        // Final-row values form complete base paths.
        vector<int> front = triangle[n - 1];

        // Rows are reduced from the base toward the top.
        for (int row = n - 2; row >= 0; row--)
        {
            // Fresh storage preserves every child value.
            vector<int> current(row + 1, 0);

            // Only valid positions in the row need answers.
            for (int col = 0; col <= row; col++)
            {
                // The straight child keeps the current column.
                int down = front[col];

                // The diagonal child uses the next column.
                int diagonal = front[col + 1];

                // The smaller child creates the current answer.
                current[col] = triangle[row][col] + min(down, diagonal);
            }

            // Shift the complete row into child-row storage.
            front = current;
        }

        // The remaining top value is the complete answer.
        return front[0];
    }
};