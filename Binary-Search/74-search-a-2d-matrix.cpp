/*
Problem: Search a 2D Matrix
Reference: https://leetcode.com/problems/search-a-2d-matrix/
Difficulty: Medium


Time Complexity: O(log(m*n))
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
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = (row * col) - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (matrix[mid / col][mid % col] == target)
            {
                return 1;
            }
            else if (matrix[mid / col][mid % col] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return 0;
    }
};