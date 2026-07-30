/*
Problem: Rotate Image
Reference: https://leetcode.com/problems/rotate-image
Difficulty: Medium


Time Complexity: O(n*n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int dim = matrix.size();

        int top = 0;
        int bottom = dim - 1;

        while (top < bottom)
        {
            for (int col = 0; col < dim; col++)
            {
                swap(matrix[top][col], matrix[bottom][col]);
            }
            top++;
            bottom--;
        }
        for (int row = 0; row < dim; row++)
        {
            for (int col = row + 1; col < dim; col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};