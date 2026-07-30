/*
Problem: Set Matrix Zeroes
Reference: https://leetcode.com/problems/set-matrix-zeroes
Difficulty: Medium


Time Complexity: O(m*n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // row = matrix[..][0]
        // col = matrix[0][..]
        int col0 = 1;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // header row
                    if (j != 0)
                    {
                        matrix[0][j] = 0; // header col
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};