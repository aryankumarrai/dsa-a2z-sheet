/*
Problem: Pascal's Triangle
Reference: https://leetcode.com/problems/pascals-triangle
Difficulty: Easy


Time Complexity: O(n*n)
Space Complexity: O(n*n)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using ll = long long;
class Solution
{
public:
    vector<int> generateRows(int n)
    {
        ll ans = 1;
        vector<int> cols = {1};
        for (int i = 1; i < n; i++)
        {
            ans *= (n - i);
            ans /= i;
            cols.push_back(ans);
        }
        return cols;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++)
        {
            res.push_back(generateRows(i));
        }
        return res;
    }
};