/*
Problem: Find a Peak Element II
Reference: https://leetcode.com/problems/find-a-peak-element-ii/
Difficulty: Medium


Time Complexity: O(mlog(n))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int maxElement(vector<vector<int>> &arr, int col)
    {
        int m = arr.size();
        int max_val = INT_MIN;
        int index = -1;

        for (int i = 0; i < m; i++)
        {
            if (arr[i][col] > max_val)
            {
                max_val = arr[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int low = 0;
        int high = mat[0].size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            int row = maxElement(mat, mid);
            int left;
            if (mid - 1 >= 0)
            {
                left = mat[row][mid - 1];
            }
            else
            {
                left = INT_MIN;
            }

            int right;
            if (mid + 1 < mat[0].size())
            {
                right = mat[row][mid + 1];
            }
            else
            {
                right = INT_MIN;
            }
            if (mat[row][mid] > left && mat[row][mid] > right)
            {
                return {row, mid};
            }
            else if (left > mat[row][mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};