/*
Problem: Search a 2D Matrix II
Reference: https://leetcode.com/problems/search-a-2d-matrix-ii/
Difficulty: Medium


Time Complexity: O(m+n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return 1;
            }
            else if (matrix[row][col] < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return 0;
    }
};